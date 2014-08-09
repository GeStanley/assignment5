int WordMultiSet::lookup(const std::string & word)
{
  auto p = wordset.equal_range(word);

  int count = std::distance(p.first, p.second);
  return count;
}
