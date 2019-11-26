
lambda {
  def two_sum(nums, target)
    nums.each_with_index do |other, index1|
      anohter =  nums.find_index {|e| e == (target - other) }
      # index1 != anohter 不能是自己 加 自己
      return [index1, anohter] if anohter && index1 != anohter
    end
  end
}

lambda {
  def two_sum(nums, target)
    hash = {}
    nums.each_with_index { |e, i | hash[e] = i }
    nums.each_with_index do |other, index1|
      anohter = hash[(target - other)]
      # index1 != anohter 不能是自己 加 自己
      return [index1, anohter] if anohter && index1 != anohter
    end
  end
}

# 最难想到的解法,不一定按出现顺序找到，比如遍历到2时，此时在hash中4还没有被保存
# 但遍历到4时，可以找到hash中的2，都是从当前元素之前的范围查找
# 此解法也不用判断是不是找到自己了
lambda {
  def two_sum(nums, target)
    hash = {}
    nums.each_with_index do |num_one, index_one|
      index_two = hash[target - num_one]
      return [index_two, index_one] if index_two

      hash[num_one] = index_one
    end
  end
}.call



nums = [3, 2, 5, 4, 6]
target = 6
p two_sum(nums, target)
