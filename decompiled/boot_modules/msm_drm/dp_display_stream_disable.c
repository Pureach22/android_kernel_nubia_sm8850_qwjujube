__int64 __fastcall dp_display_stream_disable(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned __int64 StatusReg; // x22
  __int64 (*v8)(void); // x8
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0

  if ( *(_DWORD *)(a1 + 1828) )
  {
    v3 = *(unsigned int *)(a2 + 912);
    if ( (_DWORD)v3 != 2 )
    {
      if ( (unsigned int)v3 >= 2 )
        goto LABEL_23;
      if ( *(_QWORD *)(a1 + 208 + 8 * v3) )
      {
        v5 = g_dp_display;
        *(_DWORD *)(a1 + 1880) -= *(_DWORD *)(a2 + 932);
        *(_DWORD *)(a2 + 932) = 0;
        if ( !v5 || (v6 = *(_QWORD *)(v5 + 56)) == 0 )
          v6 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        ipc_log_string(
          v6,
          "[d][%-4d]stream_id=%d, active_stream_cnt=%d, tot_dsc_blks_in_use=%d\n",
          *(_DWORD *)(StatusReg + 1800),
          *(_DWORD *)(a2 + 912),
          *(_DWORD *)(a1 + 1828),
          *(_DWORD *)(a1 + 1880));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]stream_id=%d, active_stream_cnt=%d, tot_dsc_blks_in_use=%d\n",
            *(_DWORD *)(StatusReg + 1800),
            *(_DWORD *)(a2 + 912),
            *(_DWORD *)(a1 + 1828),
            *(_DWORD *)(a1 + 1880));
        v8 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 184) + 80LL);
        if ( *((_DWORD *)v8 - 1) != 1909714074 )
          __break(0x8228u);
        result = v8();
        v10 = *(unsigned int *)(a2 + 912);
        if ( (unsigned int)v10 <= 1 )
        {
          *(_QWORD *)(a1 + 208 + 8 * v10) = 0;
          --*(_DWORD *)(a1 + 1828);
          return result;
        }
LABEL_23:
        __break(0x5512u);
        return dp_display_clear_reservation();
      }
    }
    if ( !g_dp_display || (v11 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v11 = 0;
    ipc_log_string(v11, "[e][%-4d]panel is already disabled\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_218BFE, "dp_display_stream_disable");
  }
  else
  {
    if ( !g_dp_display || (v12 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v12 = 0;
    ipc_log_string(v12, "[w][%-4d]streams already disabled cnt=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), 0);
    return printk(&unk_2762CA, "dp_display_stream_disable");
  }
}
