__int64 __fastcall policy_mgr_modify_pcl_based_on_dnbs(__int64 a1, _DWORD *a2, _BYTE *a3, unsigned int *a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w4
  __int64 result; // x0
  unsigned __int64 v18; // x24
  unsigned int v19; // w22
  unsigned __int64 v20; // x8
  unsigned int is_chan_ok_for_dnbs; // w0
  size_t v22; // x1
  unsigned int v23; // w19
  _BYTE v24[4]; // [xsp+4h] [xbp-20Ch] BYREF
  _QWORD v25[13]; // [xsp+8h] [xbp-208h] BYREF
  _DWORD s[102]; // [xsp+70h] [xbp-1A0h] BYREF
  __int64 v27; // [xsp+208h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v16 = *a4;
  memset(v25, 0, 102);
  v24[0] = 0;
  if ( v16 <= 0x66 )
  {
    if ( v16 )
    {
      v18 = 0;
      v19 = 0;
      do
      {
        is_chan_ok_for_dnbs = policy_mgr_is_chan_ok_for_dnbs(a1, a2[v18], v24, v8, v9, v10, v11, v12, v13, v14, v15);
        if ( is_chan_ok_for_dnbs )
        {
          v23 = is_chan_ok_for_dnbs;
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: Not able to check DNBS eligibility",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "policy_mgr_modify_pcl_based_on_dnbs");
          result = v23;
          goto LABEL_14;
        }
        if ( v24[0] == 1 )
        {
          if ( v19 >= 0x66 )
            __break(0x5512u);
          s[v19] = a2[v18];
          *((_BYTE *)v25 + v19++) = a3[v18];
        }
        v20 = *a4;
        ++v18;
      }
      while ( v18 < v20 );
      v22 = (unsigned int)(4 * v20);
    }
    else
    {
      v19 = 0;
      v22 = 0;
    }
    qdf_mem_set(a2, v22, 0);
    qdf_mem_set(a3, *a4, 0);
    qdf_mem_copy(a2, s, 4 * v19);
    qdf_mem_copy(a3, v25, v19);
    result = 0;
    *a4 = v19;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid PCL List Length %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "policy_mgr_modify_pcl_based_on_dnbs");
    result = 16;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
