__int64 __fastcall hdd_sysfs_pm_cminfo_show(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 *context; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w8
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x19
  __int64 *conn_info; // x20
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x3
  __int64 v40; // x2
  __int64 v41; // x3
  unsigned int v42; // w8
  char is_current_hwmode_dbs; // w0
  __int64 v44; // x8
  char v45; // w19
  unsigned __int8 v46; // w0
  __int64 v47; // x3
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w21
  __int64 v57; // x2
  __int64 v58; // x3
  __int64 v59; // x2
  __int64 v60; // x3
  __int64 v61; // x2
  __int64 v62; // x3
  __int64 v63; // x2
  __int64 v64; // x3
  __int64 v65; // x2
  __int64 v66; // x3
  __int64 v67; // x2
  __int64 v68; // x3
  __int64 v69; // x1
  __int64 v70; // x2
  __int64 v71; // x3
  __int64 v72; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v73; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v74; // [xsp+18h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v72 = 0;
  context = _cds_get_context(51, (__int64)"hdd_sysfs_pm_cminfo_show", a1, a2, a3, a4, a5, a6, a7, a8);
  v17 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_sysfs_pm_cminfo_show",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16);
  result = 0;
  if ( !v17 )
  {
    LODWORD(result) = _osif_psoc_sync_op_start(*(_QWORD *)(context[3] + 488), &v72, (__int64)"hdd_sysfs_pm_cminfo_show");
    if ( (_DWORD)result )
    {
      result = (int)result;
    }
    else
    {
      v73 = 0;
      qdf_trace_msg(0x33u, 8u, "%s: enter", v19, v20, v21, v22, v23, v24, v25, v26, "hdd_pm_cinfo_show");
      if ( wlan_hdd_validate_modules_state((__int64)context, v27, v28, v29, v30, v31, v32, v33, v34) )
      {
        conn_info = policy_mgr_get_conn_info(&v73);
        printk(&unk_96B261, v37, v38, v39);
        v42 = v73;
        if ( v73 )
        {
          v56 = 0;
          do
          {
            if ( *((_BYTE *)conn_info + 28) == 1 )
            {
              printk(&unk_9BA31F, v56, v40, v41);
              printk(&unk_9D10A8, *((unsigned int *)conn_info + 6), v57, v58);
              printk(&unk_8A2939, *((unsigned int *)conn_info + 1), v59, v60);
              printk(&unk_96B281, *((unsigned int *)conn_info + 2), v61, v62);
              printk(&unk_982848, *(unsigned int *)conn_info, v63, v64);
              printk(&unk_93F054, *((unsigned __int8 *)conn_info + 12), v65, v66);
              printk(&unk_880516, *((unsigned __int8 *)conn_info + 28), v67, v68);
              printk(&unk_96B261, v69, v70, v71);
              v42 = v73;
              conn_info = (__int64 *)((char *)conn_info + 36);
            }
            ++v56;
          }
          while ( v56 < v42 );
        }
        is_current_hwmode_dbs = policy_mgr_is_current_hwmode_dbs(*context);
        v44 = *context;
        v45 = is_current_hwmode_dbs;
        v46 = (unsigned __int8)policy_mgr_is_current_hwmode_sbs(v44);
        printk(&unk_8FC181, v45 & 1, v46 & 1, v47);
        qdf_trace_msg(0x33u, 8u, "%s: exit", v48, v49, v50, v51, v52, v53, v54, v55, "hdd_pm_cinfo_show");
        v35 = 0;
      }
      else
      {
        v35 = -22;
      }
      _osif_psoc_sync_op_stop(v72, (__int64)"hdd_sysfs_pm_cminfo_show");
      result = v35;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
