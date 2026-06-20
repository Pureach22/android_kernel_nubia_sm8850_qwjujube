__int64 __fastcall wma_init_pagefault_wakeup_history(__int64 a1)
{
  int v2; // w20
  unsigned __int64 v3; // x24
  size_t v4; // x21
  __int64 *v5; // x25
  __int64 v6; // x0
  unsigned __int64 v7; // x23
  _BOOL4 v8; // w8
  __int64 v9; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x19
  __int64 *v13; // x20

  v2 = wlan_pmo_enable_ssr_on_page_fault(*(_QWORD *)(a1 + 24));
  v3 = 0;
  v4 = 8LL * (unsigned __int8)wlan_pmo_get_min_pagefault_wakeups_for_action(*(_QWORD *)(a1 + 24));
  v5 = (__int64 *)(a1 + 4400);
  do
  {
    *((_DWORD *)v5 - 2) = 0;
    *((_BYTE *)v5 - 4) = 0;
    v6 = _qdf_mem_malloc(v4, "wma_init_pagefault_wakeup_history", 3607);
    *v5 = v6;
    if ( !v6 )
    {
      v7 = v3;
      goto LABEL_8;
    }
    v7 = v3 + 1;
    v8 = v3 < 0x31;
    v5 += 2;
    ++v3;
  }
  while ( (v8 & (v2 ^ 1) & 1) != 0 );
  if ( (v2 & 1) != 0
    || (*(_DWORD *)(a1 + 5200) = 0,
        v9 = _qdf_mem_malloc(0x186u, "wma_init_pagefault_wakeup_history", 3615),
        (*(_QWORD *)(a1 + 5192) = v9) != 0) )
  {
    *(_DWORD *)(a1 + 5208) = 0;
    *(_QWORD *)(a1 + 5216) = 0;
    return 0;
  }
LABEL_8:
  if ( (char)v7 >= 1 )
  {
    v11 = a1 + 16 * v7;
    v12 = v7 + 1;
    v13 = (__int64 *)(v11 + 4384);
    do
    {
      _qdf_mem_free(*v13);
      --v12;
      *v13 = 0;
      v13 -= 2;
    }
    while ( v12 > 1 );
  }
  return 2;
}
