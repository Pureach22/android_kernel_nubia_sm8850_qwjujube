__int64 __fastcall sub_36EB44(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v3; // x22
  unsigned int v4; // w24
  __int64 *v5; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w4
  __int64 v15; // x0

  mutex_lock(a1);
  v5 = (__int64 *)(v1 + 1816);
  do
  {
    v5 = (__int64 *)*v5;
    if ( v5 == (__int64 *)(v1 + 1816) )
    {
      mutex_unlock(v1 + 1832);
      goto LABEL_11;
    }
  }
  while ( *((_DWORD *)v5 + 4) != v4 );
  mutex_unlock(v1 + 1832);
  if ( v5 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Record already exists with handle 0x%x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_wmm_addts",
      v4);
    v14 = sme_qos_modify_req(v3, v2, *((unsigned int *)v5 + 5));
    if ( v14 <= 202 )
    {
      if ( v14 != 4 )
      {
        if ( v14 != 201 )
        {
          if ( v14 == 202 )
            JUMPOUT(0x36EF10);
          JUMPOUT(0x36EEE0);
        }
        JUMPOUT(0x36EF04);
      }
      JUMPOUT(0x36EED0);
    }
    JUMPOUT(0x36EDA4);
  }
LABEL_11:
  v15 = _qdf_mem_malloc(0x50u, "hdd_wmm_addts", 2851);
  if ( !v15 )
    JUMPOUT(0x36EC14);
  *(_DWORD *)(v15 + 16) = v4;
  return sub_36EBF8();
}
