__int64 __fastcall get_higher_refresh_resolution(
        __int64 result,
        unsigned __int16 a2,
        unsigned __int16 a3,
        unsigned __int8 a4,
        int a5)
{
  unsigned int v5; // w20
  __int64 v6; // x19
  unsigned __int16 v7; // w21
  unsigned __int16 v8; // w22
  unsigned __int8 v9; // w23
  unsigned __int16 *v10; // x9
  unsigned int v11; // w10
  unsigned int v12; // w11
  unsigned int v13; // w12
  __int64 ipc_log_context; // x0
  __int64 v15; // x8
  unsigned __int64 StatusReg; // x20

  v5 = (unsigned __int16)result;
  if ( a5 == 1 )
  {
    if ( 9 * (unsigned __int16)result != 16 * a2 )
      return result;
    v6 = edid_ctl;
    if ( edid_ctl )
    {
      v7 = a2;
      v8 = a3;
      v9 = a4;
      result = strncmp("GM002J", (const char *)edid_ctl, 6u);
      a3 = v8;
      a2 = v7;
      a4 = v9;
      if ( !(_DWORD)result
        && 9 * **(unsigned __int16 **)(v6 + 48) == 32 * *(unsigned __int16 *)(*(_QWORD *)(v6 + 48) + 2LL) )
      {
        return result;
      }
    }
  }
  else if ( !a5 && 9 * (unsigned __int16)result != 32 * a2 )
  {
    return result;
  }
  v10 = *(unsigned __int16 **)(edid_ctl + 48);
  v11 = v10[2];
  if ( v11 <= a3 )
  {
    if ( v11 != a3
      || (v12 = *v10, v12 <= v5)
      && (v13 = v10[1], v13 <= a2)
      && (v12 != v5 || v13 != a2 || *((unsigned __int8 *)v10 + 6) < (unsigned int)a4) )
    {
      *v10 = v5;
      *(_WORD *)(*(_QWORD *)(edid_ctl + 48) + 2LL) = a2;
      *(_WORD *)(*(_QWORD *)(edid_ctl + 48) + 4LL) = a3;
      *(_BYTE *)(*(_QWORD *)(edid_ctl + 48) + 6LL) = a4;
      ipc_log_context = get_ipc_log_context();
      v15 = edid_ctl;
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(
        ipc_log_context,
        "[i][%-4d]: preselected_edid_mode: %dx%d %d %d\n",
        *(_DWORD *)(StatusReg + 1800),
        **(unsigned __int16 **)(v15 + 48),
        *(unsigned __int16 *)(*(_QWORD *)(v15 + 48) + 2LL),
        *(unsigned __int16 *)(*(_QWORD *)(v15 + 48) + 4LL),
        *(unsigned __int8 *)(*(_QWORD *)(v15 + 48) + 6LL));
      if ( (_drm_debug & 4) != 0 )
        return printk(&unk_2567C7, *(unsigned int *)(StatusReg + 1800));
      else
        return printk(&unk_2684D3, "get_higher_refresh_resolution");
    }
  }
  return result;
}
