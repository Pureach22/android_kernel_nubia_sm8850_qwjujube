__int64 __fastcall mlo_mgr_reset_ap_link_info(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x19
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v13; // x22
  int v14; // w8
  int v15; // w9
  int v16; // w8
  int v17; // w9
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  _ReadStatusReg(SP_EL0);
  if ( result )
  {
    v9 = *(_QWORD *)(result + 1360);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 3880);
      if ( v10 )
      {
        v11 = *(_QWORD *)(result + 216);
        if ( v11 && (v12 = *(_QWORD *)(v11 + 80)) != 0 )
        {
          v13 = result;
          if ( *(_DWORD *)(v10 + 24) | *(unsigned __int16 *)(v10 + 28)
            && *(_DWORD *)v10 | *(unsigned __int16 *)(v10 + 4) )
          {
            wlan_crypto_free_key_by_link_id(v12, (unsigned __int8 *)v10, *(_BYTE *)(v10 + 6));
          }
          qdf_mem_set((void *)(v10 + 24), 6u, 0);
          qdf_mem_set(*(void **)(v10 + 32), 0x28u, 0);
          *(_QWORD *)(v10 + 16) = 0;
          v14 = *(_DWORD *)(v10 + 72);
          v15 = *(unsigned __int16 *)(v10 + 76);
          *(_WORD *)(v10 + 6) = 255;
          *(_BYTE *)(v10 + 40) = 0;
          if ( v14 | v15 && *(_DWORD *)(v10 + 48) | *(unsigned __int16 *)(v10 + 52) )
            wlan_crypto_free_key_by_link_id(v12, (unsigned __int8 *)(v10 + 48), *(_BYTE *)(v10 + 54));
          qdf_mem_set((void *)(v10 + 72), 6u, 0);
          qdf_mem_set(*(void **)(v10 + 80), 0x28u, 0);
          *(_WORD *)(v10 + 54) = 255;
          v16 = *(_DWORD *)(v10 + 120);
          v17 = *(unsigned __int16 *)(v10 + 124);
          *(_QWORD *)(v10 + 64) = 0;
          *(_BYTE *)(v10 + 88) = 0;
          if ( v16 | v17 && *(_DWORD *)(v10 + 96) | *(unsigned __int16 *)(v10 + 100) )
            wlan_crypto_free_key_by_link_id(v12, (unsigned __int8 *)(v10 + 96), *(_BYTE *)(v10 + 102));
          qdf_mem_set((void *)(v10 + 120), 6u, 0);
          qdf_mem_set(*(void **)(v10 + 128), 0x28u, 0);
          *(_QWORD *)(v10 + 112) = 0;
          *(_WORD *)(v10 + 102) = 255;
          *(_BYTE *)(v10 + 136) = 0;
          result = mlo_reset_cache_link_assoc_rsp(*(_QWORD *)(v13 + 1360), v18, v19, v20, v21, v22, v23, v24, v25);
        }
        else
        {
          result = qdf_trace_msg(
                     0x8Fu,
                     2u,
                     "%s: psoc NULL",
                     a2,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     "mlo_mgr_reset_ap_link_info");
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
