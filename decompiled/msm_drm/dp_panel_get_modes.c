__int64 __fastcall dp_panel_get_modes(__int64 a1, __int64 a2, _DWORD *a3)
{
  _DWORD *v3; // x8
  int v4; // w9
  int v5; // w9
  int v6; // w9
  int v7; // w9
  _QWORD *v8; // x8
  __int64 result; // x0
  int v10; // w9
  unsigned int v11; // w9
  unsigned int v12; // w10
  int v13; // w9
  int v14; // w8
  __int64 v15; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    if ( *(_BYTE *)(a1 + 872) == 1 )
    {
      if ( a1 == 8 )
      {
        ipc_log_context = get_ipc_log_context(8);
        ipc_log_string(ipc_log_context, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_24B695, "dp_panel_set_test_mode");
        return 1;
      }
      else
      {
        v3 = *(_DWORD **)(a1 + 1200);
        *a3 = v3[15];
        v4 = v3[12];
        a3[4] = v4;
        a3[2] = v3[9] - v4;
        a3[3] = v3[7] - (v3[9] + v3[15]);
        a3[1] = v3[16];
        v5 = v3[14];
        a3[8] = v5;
        a3[6] = v3[10] - v5;
        a3[7] = v3[8] - (v3[10] + v3[16]);
        v6 = v3[5];
        if ( v6 )
        {
          if ( v6 == 64 )
          {
            v7 = 30;
          }
          else if ( v6 == 32 )
          {
            v7 = 24;
          }
          else
          {
            v7 = 0;
          }
        }
        else
        {
          v7 = 18;
        }
        a3[13] = v7;
        result = 1;
        a3[5] = v3[11];
        a3[9] = v3[13];
        v10 = v3[18];
        a3[11] = v10;
        v11 = v3[7] * v10 * v3[8];
        a3[12] = v11;
        if ( v3[17] )
          v12 = 1001;
        else
          v12 = 1000;
        v13 = v11 / v12;
        a3[12] = v13;
        if ( v3[15] == 640 )
          v14 = 25170;
        else
          v14 = v13;
        a3[12] = v14;
      }
    }
    else
    {
      v8 = *(_QWORD **)(a1 + 96);
      if ( *v8 )
        return sde_edid_update_modes(a2, v8);
      else
        return 0;
    }
  }
  else
  {
    v15 = get_ipc_log_context(0);
    ipc_log_string(v15, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_get_modes");
    return 4294967274LL;
  }
  return result;
}
