__int64 __fastcall sta_info_init(__int64 a1)
{
  __int64 result; // x0
  unsigned int inited; // w0
  unsigned int v4; // w20

  result = rhltable_init_noprof(a1 + 1632, &sta_rht_params);
  if ( !(_DWORD)result )
  {
    inited = rhltable_init_noprof(a1 + 1792, &link_sta_rht_params);
    if ( inited )
    {
      v4 = inited;
      rhashtable_free_and_destroy(a1 + 1632, 0, 0);
      return v4;
    }
    else
    {
      *(_DWORD *)(a1 + 1604) = 0;
      *(_QWORD *)(a1 + 1616) = a1 + 1616;
      *(_QWORD *)(a1 + 1624) = a1 + 1616;
      init_timer_key(a1 + 1952, sta_info_cleanup, 0, 0, 0);
      return 0;
    }
  }
  return result;
}
