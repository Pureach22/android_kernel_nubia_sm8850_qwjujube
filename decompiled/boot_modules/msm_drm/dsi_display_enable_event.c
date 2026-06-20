double __fastcall dsi_display_enable_event(__int64 a1, __int64 a2, int a3, __int64 *a4, char a5)
{
  __int64 v5; // x10
  _QWORD *v6; // x8
  __int64 v7; // x11
  __int64 v8; // x10
  unsigned int v9; // w19
  _QWORD *v10; // x8
  __int64 v11; // x11
  int v12; // w8
  double result; // d0
  __int64 v14; // x10
  _QWORD *v15; // x8
  __int64 v16; // x11
  __int64 v17; // x10
  _QWORD *v18; // x8
  __int64 v19; // x11
  __int64 v20; // x8
  __int64 v21; // x9
  _DWORD *v22; // x11
  __int64 v23; // x0
  __int64 v24; // x19
  __int64 *v25; // x20
  __int64 v26; // x1
  char v27; // w21
  __int64 v28; // x20
  __int64 *v29; // x21
  __int64 v30; // x20

  if ( !a2 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display\n");
    return result;
  }
  if ( a4 )
    *(_DWORD *)a4 = a3;
  if ( a3 <= 1 )
  {
    if ( !a3 )
    {
      v9 = 4;
      v12 = *(_DWORD *)(a2 + 160);
      if ( (a5 & 1) != 0 )
        goto LABEL_27;
      goto LABEL_31;
    }
    if ( a3 == 1 )
    {
      v9 = 6;
      v12 = *(_DWORD *)(a2 + 160);
      if ( (a5 & 1) != 0 )
        goto LABEL_27;
      goto LABEL_31;
    }
    return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] unhandled event %d\n", *(const char **)(a2 + 32), a3);
  }
  if ( (unsigned int)(a3 - 2) >= 2 )
  {
    if ( a3 == 4 )
    {
      if ( a4 )
      {
        if ( *(_DWORD *)(a2 + 160) )
        {
          v14 = a4[1];
          v15 = *(_QWORD **)(a2 + 168);
          v16 = *a4;
          v15[271] = a4[2];
          v15[270] = v14;
          v15[269] = v16;
          if ( *(_DWORD *)(a2 + 160) >= 2u )
          {
            v17 = a4[1];
            v18 = *(_QWORD **)(a2 + 216);
            v19 = *a4;
            v18[271] = a4[2];
            v18[270] = v17;
            v18[269] = v19;
          }
        }
      }
      v20 = *(_QWORD *)(a2 + 1632);
      if ( v20 != -1 )
      {
        v21 = *(_QWORD *)(a2 + 168);
        v22 = *(_DWORD **)(v21 + 2168);
        if ( v22 )
        {
          v23 = *(_QWORD *)(v21 + 2160);
          v24 = a2;
          v25 = a4;
          v26 = *(unsigned int *)(v21 + 2152);
          v27 = a5;
          if ( *(v22 - 1) != 863793901 )
            __break(0x822Bu);
          ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v22)(
            v23,
            v26,
            0,
            HIDWORD(v20),
            (unsigned int)v20,
            0,
            0);
          a5 = v27;
          a4 = v25;
          a2 = v24;
        }
      }
LABEL_26:
      v9 = 11;
      v12 = *(_DWORD *)(a2 + 160);
      if ( (a5 & 1) != 0 )
        goto LABEL_27;
      goto LABEL_31;
    }
    return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] unhandled event %d\n", *(const char **)(a2 + 32), a3);
  }
  if ( !a4 )
    goto LABEL_26;
  if ( !*(_DWORD *)(a2 + 160) )
    goto LABEL_26;
  v5 = a4[1];
  v6 = *(_QWORD **)(a2 + 168);
  v7 = *a4;
  v6[268] = a4[2];
  v6[267] = v5;
  v6[266] = v7;
  if ( *(_DWORD *)(a2 + 160) < 2u )
    goto LABEL_26;
  v8 = a4[1];
  v9 = 11;
  v10 = *(_QWORD **)(a2 + 216);
  v11 = *a4;
  v10[268] = a4[2];
  v10[267] = v8;
  v10[266] = v11;
  v12 = *(_DWORD *)(a2 + 160);
  if ( (a5 & 1) != 0 )
  {
LABEL_27:
    if ( v12 )
    {
      v28 = a2;
      v29 = a4;
      dsi_ctrl_enable_status_interrupt(*(int **)(a2 + 168), v9, a4);
      if ( *(_DWORD *)(v28 + 160) >= 2u )
        dsi_ctrl_enable_status_interrupt(*(int **)(v28 + 216), v9, v29);
    }
    return result;
  }
LABEL_31:
  if ( v12 )
  {
    v30 = a2;
    dsi_ctrl_disable_status_interrupt(*(int **)(a2 + 168), v9);
    if ( *(_DWORD *)(v30 + 160) >= 2u )
      dsi_ctrl_disable_status_interrupt(*(int **)(v30 + 216), v9);
  }
  return result;
}
