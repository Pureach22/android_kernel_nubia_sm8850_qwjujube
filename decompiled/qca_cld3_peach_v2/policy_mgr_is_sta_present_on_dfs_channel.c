__int64 __fastcall policy_mgr_is_sta_present_on_dfs_channel(__int64 a1, _BYTE *a2, _DWORD *a3, _DWORD *a4)
{
  __int64 context; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 *v25; // x24
  char *v26; // x25
  unsigned int v27; // w23

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v16 = context;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_8D4F00) != 1
      || ((unsigned int)pm_conc_connection_list | 2) != 2
      || (v25 = &pm_conc_connection_list,
          v26 = (char *)&pm_conc_connection_list + 4,
          (wlan_reg_is_dfs_for_freq(
             *(_QWORD *)(v16 + 8),
             HIDWORD(pm_conc_connection_list),
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24)
         & 1) == 0)
      && ((v26 = (char *)&pm_conc_connection_list + 4, !wlan_reg_is_5ghz_ch_freq(HIDWORD(pm_conc_connection_list)))
       || (_DWORD)qword_8D4EF0 != 7) )
    {
      if ( BYTE4(qword_8D4F24) != 1
        || ((unsigned int)qword_8D4F0C | 2) != 2
        || (v25 = &qword_8D4F0C,
            v26 = (char *)&qword_8D4F0C + 4,
            (wlan_reg_is_dfs_for_freq(
               *(_QWORD *)(v16 + 8),
               HIDWORD(qword_8D4F0C),
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24)
           & 1) == 0)
        && ((v26 = (char *)&qword_8D4F0C + 4, !wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F0C)))
         || (_DWORD)qword_8D4F14 != 7) )
      {
        if ( BYTE4(qword_8D4F48) != 1
          || ((unsigned int)qword_8D4F30 | 2) != 2
          || (v25 = &qword_8D4F30,
              v26 = (char *)&qword_8D4F30 + 4,
              (wlan_reg_is_dfs_for_freq(
                 *(_QWORD *)(v16 + 8),
                 HIDWORD(qword_8D4F30),
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24)
             & 1) == 0)
          && ((v26 = (char *)&qword_8D4F30 + 4, !wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F30)))
           || (_DWORD)qword_8D4F38 != 7) )
        {
          if ( BYTE4(qword_8D4F6C) != 1
            || ((unsigned int)qword_8D4F54 | 2) != 2
            || (v25 = &qword_8D4F54,
                v26 = (char *)&qword_8D4F54 + 4,
                (wlan_reg_is_dfs_for_freq(
                   *(_QWORD *)(v16 + 8),
                   HIDWORD(qword_8D4F54),
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24)
               & 1) == 0)
            && ((v26 = (char *)&qword_8D4F54 + 4, !wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F54)))
             || (_DWORD)qword_8D4F5C != 7) )
          {
            if ( BYTE4(qword_8D4F90) != 1 || ((unsigned int)qword_8D4F78 | 2) != 2 )
            {
              v27 = 0;
              goto LABEL_30;
            }
            v25 = &qword_8D4F78;
            v26 = (char *)&qword_8D4F78 + 4;
            if ( (wlan_reg_is_dfs_for_freq(
                    *(_QWORD *)(v16 + 8),
                    HIDWORD(qword_8D4F78),
                    v17,
                    v18,
                    v19,
                    v20,
                    v21,
                    v22,
                    v23,
                    v24)
                & 1) == 0 )
            {
              v26 = (char *)&qword_8D4F78 + 4;
              v27 = 0;
              if ( !wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F78)) || (_DWORD)qword_8D4F80 != 7 )
                goto LABEL_30;
            }
          }
        }
      }
    }
    v27 = 1;
    *a2 = *((_DWORD *)v25 + 6);
    *a3 = *(_DWORD *)v26;
    *a4 = *((_DWORD *)v25 + 2);
LABEL_30:
    qdf_mutex_release(v16 + 56);
    return v27;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid Context",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "policy_mgr_is_sta_present_on_dfs_channel");
  return 0;
}
