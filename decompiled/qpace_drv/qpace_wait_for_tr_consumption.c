__int64 __fastcall qpace_wait_for_tr_consumption(int a1, char a2)
{
  __int64 v2; // x21
  __int64 v4; // x22
  __int64 v5; // x9
  __int64 v6; // x23
  __int64 result; // x0
  __int64 v8; // x0

  v2 = a1;
  v4 = ev_rings + ((__int64)a1 << 6);
  v5 = *(_QWORD *)(v4 + 40);
  if ( v5 == *(_QWORD *)(v4 + 32) + 4064LL )
    v6 = *(_QWORD *)(v4 + 32);
  else
    v6 = v5 + 32;
  do
  {
    v8 = ev_rings + (v2 << 6);
    if ( (a2 & 1) != 0 )
    {
      for ( result = try_wait_for_completion(v8); (result & 1) == 0; result = try_wait_for_completion(ev_rings + (v2 << 6)) )
        _const_udelay(4295);
    }
    else
    {
      result = wait_for_completion(v8);
    }
  }
  while ( ((*(_DWORD *)(v6 + 16) >> 30) & 1) != *(_BYTE *)(v4 + 56) );
  return result;
}
