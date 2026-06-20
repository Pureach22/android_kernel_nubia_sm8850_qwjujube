__int64 __fastcall dp_panel_tpg_config(__int64 a1, int a2)
{
  __int64 v2; // x8
  int v3; // w9
  int v4; // w10
  int v5; // w11
  int v6; // w10
  int v7; // w12
  int v8; // w11
  int v9; // w13
  __int64 (__fastcall *v10)(_QWORD); // x9
  __int64 v11; // x0
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  __int64 v14; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 912) >= 2u )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 912));
      return printk(&unk_26EFE9, "dp_panel_tpg_config");
    }
    else if ( (*(_BYTE *)(a1 + 1232) & 1) != 0 )
    {
      v2 = *(_QWORD *)(a1 + 1216);
      if ( a2 )
      {
        v3 = *(_DWORD *)(a1 + 112)
           + *(_DWORD *)(a1 + 120)
           + *(_DWORD *)(a1 + 116)
           + (*(_DWORD *)(a1 + 104) >> *(_BYTE *)(a1 + 160));
        *(_DWORD *)(v2 + 160) = v3;
        v4 = *(_DWORD *)(a1 + 128) + *(_DWORD *)(a1 + 136) + *(_DWORD *)(a1 + 108) + *(_DWORD *)(a1 + 132);
        *(_DWORD *)(v2 + 164) = v4;
        v5 = (*(_DWORD *)(a1 + 128) + *(_DWORD *)(a1 + 136)) * v3;
        *(_DWORD *)(v2 + 168) = v5;
        v6 = (v4 - *(_DWORD *)(a1 + 132)) * v3 - 1;
        *(_DWORD *)(v2 + 172) = v6;
        *(_DWORD *)(v2 + 168) = *(_DWORD *)(a1 + 120) + *(_DWORD *)(a1 + 112) + v5;
        *(_DWORD *)(v2 + 172) = v6 - *(_DWORD *)(a1 + 116);
        v7 = *(_DWORD *)(a1 + 112);
        v9 = *(_DWORD *)(a1 + 116);
        v8 = *(_DWORD *)(a1 + 120);
        *(_DWORD *)(v2 + 176) = *(_DWORD *)(a1 + 136);
        *(_DWORD *)(v2 + 180) = *(_DWORD *)(a1 + 120) | (v3 << 16);
        *(_DWORD *)(v2 + 184) = (v8 + v7) | ((v3 + ~v9) << 16);
        v10 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1216) + 624LL);
      }
      else
      {
        v10 = *(__int64 (__fastcall **)(_QWORD))(v2 + 624);
      }
      if ( *((_DWORD *)v10 - 1) != 1646357783 )
        __break(0x8229u);
      return v10(v2);
    }
    else
    {
      v11 = get_ipc_log_context(a1);
      StatusReg = _ReadStatusReg(SP_EL0);
      result = ipc_log_string(
                 v11,
                 "[d][%-4d]DP panel not enabled, handle TPG on next panel on\n",
                 *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]DP panel not enabled, handle TPG on next panel on\n",
                 *(_DWORD *)(StatusReg + 1800));
    }
  }
  else
  {
    v14 = get_ipc_log_context(0);
    ipc_log_string(v14, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_panel_tpg_config");
  }
  return result;
}
