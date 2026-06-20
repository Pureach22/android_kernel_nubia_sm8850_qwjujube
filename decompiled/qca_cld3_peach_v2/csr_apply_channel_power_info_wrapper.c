void *__fastcall csr_apply_channel_power_info_wrapper(__int64 a1)
{
  __int64 v2; // x0
  _BYTE *v3; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w8
  unsigned __int64 v21; // x22
  int *v22; // x25
  char v23; // w0
  _BYTE *v24; // x8
  int v25; // t1
  void *result; // x0
  __int16 v27; // [xsp+4h] [xbp-Ch] BYREF
  char v28; // [xsp+6h] [xbp-Ah]
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v27 = 0;
  v2 = _qdf_mem_malloc(0x92u, "csr_diag_reset_country_information", 321);
  if ( v2 )
  {
    v3 = (_BYTE *)v2;
    host_diag_log_set_code(v2, 5272);
    host_diag_log_set_length(v3, 146);
    v3[12] = 1;
    wlan_reg_read_current_country(*(_QWORD *)(a1 + 21624), &v27, v4, v5, v6, v7, v8, v9, v10, v11);
    qdf_mem_copy(v3 + 142, &v27, 3u);
    v20 = *(unsigned __int8 *)(a1 + 16604);
    v3[13] = v20;
    if ( (unsigned int)(v20 - 65) >= 0xFFFFFFC0 )
    {
      v21 = 0;
      v22 = (int *)(a1 + 15412);
      do
      {
        v23 = wlan_reg_freq_to_chan(
                *(_QWORD *)(a1 + 21632),
                *(_DWORD *)(a1 + 16608 + 4 * v21),
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19);
        if ( v21 == 64 )
          __break(0x5512u);
        v24 = &v3[v21++ + 78];
        *(v24 - 64) = v23;
        v25 = *v22;
        v22 += 3;
        *v24 = v25;
      }
      while ( v21 < *(unsigned __int8 *)(a1 + 16604) );
    }
    host_diag_log_submit(v3);
    _qdf_mem_free((__int64)v3);
  }
  csr_prune_channel_list_for_mode((void *)a1, (_BYTE *)(a1 + 16604));
  csr_save_channel_power_for_band(a1, 0);
  csr_save_channel_power_for_band(a1, 1);
  csr_apply_channel_power_info_to_fw(a1, (unsigned __int8 *)(a1 + 16604));
  result = qdf_mem_set((void *)(a1 + 15000), 0x194u, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
