__int64 __fastcall _sta_info_destroy(__int64 a1)
{
  __int64 result; // x0

  result = _sta_info_destroy_part1();
  if ( !(_DWORD)result )
  {
    synchronize_net(result);
    _sta_info_destroy_part2(a1, 1);
    return 0;
  }
  return result;
}
