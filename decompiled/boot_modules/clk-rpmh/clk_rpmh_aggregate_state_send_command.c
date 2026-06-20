__int64 __fastcall clk_rpmh_aggregate_state_send_command(__int64 a1, char a2)
{
  int v4; // w8
  __int64 v5; // x9
  int v6; // w8
  int v7; // w21
  int v8; // w22
  int v9; // w9
  int v10; // w8
  unsigned int v11; // w0
  unsigned int v12; // w0
  __int64 v13; // x0
  unsigned int v14; // w0
  __int64 v15; // x9
  __int64 result; // x0
  unsigned int v17; // w21
  const char *v18; // x2
  int v19; // w8
  const char *v20; // x2
  const char *v21; // x1
  int v22; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
    v4 = *(_DWORD *)(a1 + 56);
  else
    v4 = 0;
  v5 = *(_QWORD *)(a1 + 72);
  *(_DWORD *)(a1 + 44) = v4;
  v23 = 0;
  v6 = *(_DWORD *)(v5 + 44) | v4;
  *(_DWORD *)(a1 + 48) = v6;
  *(_DWORD *)(v5 + 48) = v6;
  v7 = *(_DWORD *)(a1 + 48);
  v8 = *(_DWORD *)(a1 + 40);
  v9 = *(_DWORD *)(a1 + 52) ^ v7;
  v10 = v7;
  v22 = *(_DWORD *)(a1 + 36);
  if ( (v9 & 1) != 0 )
  {
    if ( (v7 & 1) != 0 )
      LODWORD(v23) = v8;
    v11 = rpmh_write_async(*(_QWORD *)(a1 + 64), 0, &v22, 1);
    if ( v11 )
    {
      v17 = v11;
      v18 = "sleep";
      goto LABEL_26;
    }
    v10 = *(_DWORD *)(a1 + 48);
    v9 = v10 ^ *(_DWORD *)(a1 + 52);
  }
  if ( (v9 & 2) != 0 )
  {
    if ( (v7 & 2) != 0 )
      LODWORD(v23) = v8;
    v12 = rpmh_write_async(*(_QWORD *)(a1 + 64), 1, &v22, 1);
    if ( v12 )
    {
      v17 = v12;
      v18 = "wake";
      goto LABEL_26;
    }
    v10 = *(_DWORD *)(a1 + 48);
    v9 = v10 ^ *(_DWORD *)(a1 + 52);
  }
  if ( (v9 & 4) == 0 )
  {
LABEL_20:
    v15 = *(_QWORD *)(a1 + 72);
    result = 0;
    *(_DWORD *)(a1 + 52) = v10;
    *(_DWORD *)(v15 + 52) = v10;
    goto LABEL_21;
  }
  if ( (v7 & 4) != 0 )
    LODWORD(v23) = v8;
  v13 = *(_QWORD *)(a1 + 64);
  if ( v7 )
  {
    v14 = rpmh_write(v13, 2, &v22, 1);
    if ( !v14 )
    {
LABEL_19:
      v10 = *(_DWORD *)(a1 + 48);
      goto LABEL_20;
    }
  }
  else
  {
    v14 = rpmh_write_async(v13, 2, &v22, 1);
    if ( !v14 )
      goto LABEL_19;
  }
  v17 = v14;
  v18 = "active";
LABEL_26:
  dev_err(*(_QWORD *)(a1 + 64), "set %s state of %s failed: (%d)\n", v18, *(const char **)(a1 + 24), v17);
  if ( (a2 & 1) != 0 )
  {
    v19 = 0;
    v20 = "enable";
  }
  else
  {
    v19 = *(_DWORD *)(a1 + 56);
    v20 = "disable";
  }
  v21 = *(const char **)(a1 + 24);
  *(_DWORD *)(a1 + 44) = v19;
  _warn_printk("clk: %s failed to %s\n", v21, v20);
  result = v17;
  __break(0x800u);
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
