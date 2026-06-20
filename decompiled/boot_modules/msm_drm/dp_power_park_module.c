__int64 __fastcall dp_power_park_module(_QWORD *a1, unsigned int a2)
{
  __int64 v2; // x10
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 result; // x0
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v12; // x0
  unsigned int v13; // w20
  __int64 ipc_log_context; // x0
  unsigned int v15; // w19
  __int64 v16; // x0

  v2 = a2 - 3;
  if ( (unsigned int)v2 > 2 )
    return 0;
  v3 = *(_QWORD *)((char *)a1 + (unsigned int)(16 * v2) + 24);
  if ( v3 )
  {
    if ( a1[6] )
    {
      v4 = v2 | 0xC4;
      if ( (*((_BYTE *)a1 + (v2 | 0xC4)) & 1) != 0 )
        return 0;
      v8 = *a1;
      v9 = clk_set_parent(v3);
      if ( (_DWORD)v9 )
      {
        v13 = v9;
        ipc_log_context = get_ipc_log_context(v9);
        ipc_log_string(
          ipc_log_context,
          "[e][%-4d]unable to set xo parent on clk %d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          a2);
        printk(&unk_26B4F2, "dp_power_park_module");
        return v13;
      }
      else
      {
        v10 = v8 + 48LL * a2;
        *(_QWORD *)(*(_QWORD *)(v10 + 56) + 48LL) = 19200000;
        result = msm_dss_clk_set_rate(*(_QWORD *)(v10 + 56), *(unsigned int *)(v10 + 48));
        if ( (_DWORD)result )
        {
          v15 = result;
          v16 = get_ipc_log_context(result);
          ipc_log_string(v16, "[e][%-4d]failed to set clk rate.\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
          printk(&unk_2723B0, "dp_power_park_module");
          return v15;
        }
        else
        {
          *((_BYTE *)a1 + v4) = 1;
        }
      }
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    v12 = get_ipc_log_context(a1);
    ipc_log_string(v12, "[w][%-4d]clk type %d not supported\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a2);
    printk(&unk_259596, "dp_power_park_module");
    return 4294967274LL;
  }
  return result;
}
