__int64 __fastcall ipclite_probe(__int64 a1)
{
  __int64 v1; // x20
  int variable_u32_array; // w0
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x6
  __int64 v9; // x7
  int v10; // w0
  __int64 (__fastcall *v11)(); // x9
  __int64 (__fastcall *v12)(); // x12
  __int64 (__fastcall *v13)(); // x11
  __int64 (__fastcall *v14)(); // x12
  __int64 (__fastcall *v15)(); // x10
  __int64 (__fastcall *v16)(); // x11
  __int64 (__fastcall *v17)(); // x12
  unsigned int v18; // w19
  const char *v19; // x0
  const char *v20; // x0
  char v22; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)(a1 + 760);
  variable_u32_array = of_property_read_variable_u32_array(v1, "major_version", &major_ver, 1, 0);
  if ( variable_u32_array < 0 )
  {
    v18 = variable_u32_array & (variable_u32_array >> 31);
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_11473, "ipclite", "ipclite_version_setup");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_37;
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        goto LABEL_37;
      }
      v19 = "APPS:%s:failed to parse major_vesion\n";
LABEL_36:
      ipclite_inmem_log(v19, (__int64)"ERR", v4, v5, v6, v7, v8, v9, v22);
    }
LABEL_37:
    if ( (ipclite_debug_level & 1) == 0 )
      goto LABEL_50;
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_E659, "ipclite", "ipclite_probe");
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_50;
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      goto LABEL_50;
    }
    v20 = "APPS:%s:IPCLite Version Setup Failed\n";
    goto LABEL_49;
  }
  v10 = of_property_read_variable_u32_array(v1, "minor_version", &minor_ver, 1, 0);
  if ( v10 < 0 )
  {
    v18 = v10 & (v10 >> 31);
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_F01C, "ipclite", "ipclite_version_setup");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_37;
        goto LABEL_35;
      }
      if ( (ipclite_debug_control & 4) != 0 )
      {
LABEL_35:
        v19 = "APPS:%s:failed to parse minor_vesion\n";
        goto LABEL_36;
      }
    }
    goto LABEL_37;
  }
  if ( major_ver == 1 && !minor_ver )
  {
    v11 = api_list_version[0];
    v12 = off_338[0];
    if ( !api_list_version[0] )
      v11 = (__int64 (__fastcall *)())api_list_t;
    if ( !off_338[0] )
      v12 = (__int64 (__fastcall *)())off_E448;
    v13 = (__int64 (__fastcall *)())off_E458;
    api_list_t = v11;
    off_E448 = v12;
    if ( off_340[0] )
      v14 = off_340[0];
    else
      v14 = (__int64 (__fastcall *)())off_E450;
    if ( off_348[0] )
      v13 = off_348[0];
    v15 = off_360[0];
    off_E450 = v14;
    off_E458 = v13;
    if ( off_350[0] )
      v16 = off_350[0];
    else
      v16 = (__int64 (__fastcall *)())off_E460;
    if ( off_358[0] )
      v17 = off_358[0];
    else
      v17 = (__int64 (__fastcall *)())off_E468;
    if ( !off_360[0] )
      v15 = (__int64 (__fastcall *)())off_E470;
    off_E460 = v16;
    off_E468 = v17;
    off_E470 = v15;
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != -939997060 )
        __break(0x8229u);
      v18 = ((__int64 (__fastcall *)(__int64))v11)(a1);
      if ( !v18 )
        return v18;
      if ( (ipclite_debug_level & 1) == 0 )
      {
LABEL_50:
        if ( (ipclite_debug_level & 1) != 0 )
        {
          if ( (ipclite_debug_control & 1) != 0 )
          {
            printk(&unk_10F24, "ipclite", "ipclite_probe");
            if ( (ipclite_debug_control & 4) == 0 )
              return v18;
            goto LABEL_53;
          }
          if ( (ipclite_debug_control & 4) != 0 )
LABEL_53:
            ipclite_inmem_log("APPS:%s:IPCLite probe failed\n", (__int64)"ERR", v4, v5, v6, v7, v8, v9, v22);
        }
        return v18;
      }
      goto LABEL_46;
    }
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) == 0 )
      {
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_45;
        goto LABEL_44;
      }
      printk(&unk_FF4F, "ipclite", "ipclite_init");
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_44:
        ipclite_inmem_log(
          "APPS:%s:Unassigned function : %s",
          (__int64)"ERR",
          (__int64)"ipclite_init",
          v5,
          v6,
          v7,
          v8,
          v9,
          v22);
    }
LABEL_45:
    v18 = -22;
    if ( (ipclite_debug_level & 1) == 0 )
      goto LABEL_50;
LABEL_46:
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_10F03, "ipclite", "ipclite_probe");
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_50;
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      goto LABEL_50;
    }
    v20 = "APPS:%s:IPCLite Init Failed\n";
LABEL_49:
    ipclite_inmem_log(v20, (__int64)"ERR", v4, v5, v6, v7, v8, v9, v22);
    goto LABEL_50;
  }
  __break(0x800u);
  return ipclite_driver_suspend();
}
