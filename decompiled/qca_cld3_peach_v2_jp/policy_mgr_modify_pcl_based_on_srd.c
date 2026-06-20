__int64 __fastcall policy_mgr_modify_pcl_based_on_srd(__int64 a1, _DWORD *a2, _BYTE *a3, unsigned int *a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  __int64 v18; // x23
  unsigned __int64 v19; // x24
  unsigned int v20; // w22
  unsigned __int64 v21; // x8
  size_t v22; // x1
  _QWORD v23[13]; // [xsp+8h] [xbp-208h] BYREF
  _DWORD s[102]; // [xsp+70h] [xbp-1A0h] BYREF
  __int64 v25; // [xsp+208h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  memset(v23, 0, 102);
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( *a4 <= 0x66 )
    {
      if ( *a4 )
      {
        v18 = context;
        v19 = 0;
        v20 = 0;
        do
        {
          if ( (wlan_reg_is_etsi_srd_chan_for_freq(*(_QWORD *)(v18 + 8), a2[v19], v9, v10, v11, v12, v13, v14, v15, v16)
              & 1) == 0 )
          {
            if ( v20 >= 0x66 )
              __break(0x5512u);
            s[v20] = a2[v19];
            *((_BYTE *)v23 + v20++) = a3[v19];
          }
          v21 = *a4;
          ++v19;
        }
        while ( v19 < v21 );
        v22 = (unsigned int)(4 * v21);
      }
      else
      {
        v20 = 0;
        v22 = 0;
      }
      qdf_mem_set(a2, v22, 0);
      qdf_mem_set(a3, *a4, 0);
      qdf_mem_copy(a2, s, 4 * v20);
      qdf_mem_copy(a3, v23, v20);
      result = 0;
      *a4 = v20;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid PCL List Length %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "policy_mgr_modify_pcl_based_on_srd");
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_modify_pcl_based_on_srd");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
