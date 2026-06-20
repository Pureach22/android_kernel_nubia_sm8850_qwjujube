__int64 __fastcall hdd_get_random_nan_mac_addr(_DWORD *a1, _BYTE *a2)
{
  unsigned int v4; // w24
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 adapter; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x23
  _BYTE *v25; // x10
  int v26; // w8
  char v27; // w8
  _BYTE v28[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v4 = 0;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  while ( 1 )
  {
    adapter = hdd_get_adapter((__int64)a1, 11);
    if ( adapter )
    {
      v24 = adapter;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: NDI already exists, deriving next mac",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_get_random_nan_mac_addr");
      qdf_mem_copy(a2, (const void *)(v24 + 1617), 6u);
      get_random_bytes(v28, 1);
      v25 = &a2[(unsigned __int64)(v28[0] & 0x1F) >> 3];
      v26 = 1 << (v28[0] & 7);
      v28[0] &= 0x1Fu;
      v25[1] ^= v26;
      if ( !a1[956] )
        goto LABEL_20;
    }
    else
    {
      get_random_bytes(a2, 6);
      v27 = a2[5];
      *a2 = 2;
      a2[5] = v27 & 0xFE;
      if ( !a1[956] )
        goto LABEL_20;
    }
    if ( !(unsigned int)qdf_mem_cmp((char *)a1 + 3751, a2, 6u) )
      goto LABEL_3;
    if ( a1[956] >= 2u )
    {
      if ( !(unsigned int)qdf_mem_cmp((char *)a1 + 3757, a2, 6u) )
        goto LABEL_3;
      if ( a1[956] >= 3u )
      {
        if ( !(unsigned int)qdf_mem_cmp((char *)a1 + 3763, a2, 6u) )
          goto LABEL_3;
        if ( a1[956] >= 4u )
        {
          if ( !(unsigned int)qdf_mem_cmp((char *)a1 + 3769, a2, 6u) )
            goto LABEL_3;
          if ( a1[956] >= 5u )
          {
            if ( !(unsigned int)qdf_mem_cmp((char *)a1 + 3775, a2, 6u) )
              goto LABEL_3;
            if ( a1[956] >= 6u )
            {
              if ( !(unsigned int)qdf_mem_cmp((char *)a1 + 3781, a2, 6u) )
                goto LABEL_3;
              if ( a1[956] > 6u )
                goto LABEL_33;
            }
          }
        }
      }
    }
LABEL_20:
    if ( !a1[957] )
      goto LABEL_2;
    if ( (unsigned int)qdf_mem_cmp((char *)a1 + 3787, a2, 6u) )
    {
      if ( a1[957] < 2u )
        goto LABEL_2;
      if ( (unsigned int)qdf_mem_cmp((char *)a1 + 3793, a2, 6u) )
      {
        if ( a1[957] < 3u )
          goto LABEL_2;
        if ( (unsigned int)qdf_mem_cmp((char *)a1 + 3799, a2, 6u) )
        {
          if ( a1[957] < 4u )
            goto LABEL_2;
          if ( (unsigned int)qdf_mem_cmp((char *)a1 + 3805, a2, 6u) )
          {
            if ( a1[957] < 5u )
              goto LABEL_2;
            if ( (unsigned int)qdf_mem_cmp((char *)a1 + 3811, a2, 6u) )
            {
              if ( a1[957] < 6u )
                goto LABEL_2;
              if ( (unsigned int)qdf_mem_cmp((char *)a1 + 3817, a2, 6u) )
                break;
            }
          }
        }
      }
    }
LABEL_3:
    if ( v4++ >= 0xF )
      goto LABEL_34;
  }
  if ( a1[957] <= 6u )
  {
LABEL_2:
    result = hdd_get_adapter_by_macaddr((__int64)a1, a2);
    if ( !result )
      goto LABEL_35;
    goto LABEL_3;
  }
LABEL_33:
  __break(0x5512u);
LABEL_34:
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: unable to get non-pre-existing mac address in %d attempts",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "hdd_get_random_nan_mac_addr",
    16);
  result = 4294967274LL;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
