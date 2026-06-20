__int64 __fastcall clk_rpmh_probe(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *match_data; // x0
  _QWORD *v3; // x20
  __int64 v4; // x25
  unsigned __int64 v5; // x21
  int v6; // w26
  __int64 v7; // x22
  __int64 v8; // x8
  const char *v9; // x23
  int addr; // w0
  int v11; // w24
  _DWORD *aux_data; // x0
  int v13; // w8
  unsigned int v14; // w0
  const char **v15; // x8
  const char *name; // x2
  unsigned int v17; // w0
  unsigned int v18; // w19
  unsigned int v20; // w20
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 + 16;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  match_data = (_QWORD *)of_device_get_match_data(a1 + 16);
  if ( !match_data )
  {
LABEL_23:
    v18 = -19;
    goto LABEL_24;
  }
  v3 = match_data;
  if ( match_data[1] )
  {
    v4 = *match_data;
    v5 = 0;
    v6 = 1;
    do
    {
      v21[0] = 0;
      v7 = *(_QWORD *)(v4 + 8 * v5);
      if ( !v7 )
        goto LABEL_5;
      v8 = *(_QWORD *)(v7 + 16);
      v9 = *(const char **)v8;
      if ( *(_UNKNOWN **)(v8 + 8) != &clk_fixed_factor_ops )
      {
        addr = cmd_db_read_addr(*(_QWORD *)(v7 + 24));
        if ( !addr )
        {
          *(_QWORD *)(v4 + 8 * v5) = 0;
          if ( (*(_BYTE *)(v7 + 33) & 1) == 0 )
          {
            _warn_printk("clk-rpmh: Missing RPMh resource address for %s\n", *(const char **)(v7 + 24));
            __break(0x800u);
            goto LABEL_23;
          }
          goto LABEL_5;
        }
        v11 = addr;
        aux_data = (_DWORD *)cmd_db_read_aux_data(*(_QWORD *)(v7 + 24), v21);
        if ( (unsigned __int64)aux_data >= 0xFFFFFFFFFFFFF001LL )
        {
          v18 = (unsigned int)aux_data;
          _warn_printk(
            "clk-rpmh: error reading RPMh aux data for %s (%d)\n",
            *(const char **)(v7 + 24),
            (_DWORD)aux_data);
          __break(0x800u);
          goto LABEL_24;
        }
        if ( v21[0] == 8 )
          *(_DWORD *)(v7 + 60) = 1000 * *aux_data;
        v13 = *(_DWORD *)(v7 + 36);
        *(_QWORD *)(v7 + 64) = v1;
        *(_DWORD *)(v7 + 36) = v13 + v11;
        v7 = *(_QWORD *)(v4 + 8 * v5);
      }
      v14 = devm_clk_hw_register(v1, v7);
      if ( v14 )
      {
        v20 = v14;
        dev_err(v1, "failed to register %s\n", v9);
LABEL_27:
        v18 = v20;
        goto LABEL_24;
      }
      if ( (unsigned int)clk_hw_debug_register(v1, *(_QWORD *)(v4 + 8 * v5)) )
      {
        v15 = *(const char ***)(*(_QWORD *)(v4 + 8 * v5) + 16LL);
        if ( v15 )
          name = *v15;
        else
          name = (const char *)clk_hw_get_name();
        dev_warn(v1, "Failed to add %s to debug list\n", name);
      }
LABEL_5:
      v5 = v6++;
    }
    while ( v3[1] > v5 );
  }
  v17 = devm_of_clk_add_hw_provider(v1, of_clk_rpmh_hw_get, v3);
  if ( v17 )
  {
    v20 = v17;
    dev_err(v1, "Failed to add clock provider\n");
    goto LABEL_27;
  }
  v18 = 0;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v18;
}
