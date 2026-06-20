__int64 __fastcall dsi_display_set_tpg_state(__int64 a1, char a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  char v6; // w20
  unsigned int v10; // w0
  unsigned int v11; // w20
  __int64 v12; // x4
  unsigned int v14; // w0
  __int64 v15; // x4
  unsigned int v16; // w0
  unsigned int v17; // w0

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 160) )
    {
      v6 = a2;
      v10 = dsi_ctrl_set_tpg_state(*(_QWORD *)(a1 + 168), a2 & 1, a3, a4, a5);
      if ( v10 )
      {
        v11 = v10;
        v12 = 0;
LABEL_5:
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to set tpg state for host_%d\n",
          *(_QWORD *)(a1 + 32),
          v12);
        return v11;
      }
      a2 = v6;
      if ( (v6 & 1) != 0 && *(_DWORD *)(*(_QWORD *)(a1 + 168) + 2440LL) == 2 )
      {
        v14 = ((__int64 (*)(void))dsi_ctrl_trigger_test_pattern)();
        a2 = v6;
        if ( v14 )
        {
          v11 = v14;
          v15 = 0;
LABEL_12:
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] failed to start tpg for host_%d\n",
            *(_QWORD *)(a1 + 32),
            v15);
          return v11;
        }
      }
      if ( *(_DWORD *)(a1 + 160) >= 2u )
      {
        v16 = dsi_ctrl_set_tpg_state(*(_QWORD *)(a1 + 216), a2 & 1, a3, a4, a5);
        if ( v16 )
        {
          v11 = v16;
          v12 = 1;
          goto LABEL_5;
        }
        a2 = v6;
        if ( (v6 & 1) != 0 && *(_DWORD *)(*(_QWORD *)(a1 + 216) + 2440LL) == 2 )
        {
          v17 = ((__int64 (*)(void))dsi_ctrl_trigger_test_pattern)();
          a2 = v6;
          if ( v17 )
          {
            v11 = v17;
            v15 = 1;
            goto LABEL_12;
          }
        }
      }
    }
    *(_BYTE *)(a1 + 1216) = a2 & 1;
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
}
