__int64 __fastcall ipa3_attrib_dump_eq(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x2
  __int64 v18; // x3

  _ReadStatusReg(SP_EL0);
  if ( !*(_BYTE *)(a1 + 2) )
  {
    if ( !*(_BYTE *)(a1 + 4) )
      goto LABEL_3;
LABEL_50:
    printk(&unk_3CF68F, *(unsigned __int8 *)(a1 + 5));
    if ( !*(_BYTE *)(a1 + 48) )
      goto LABEL_4;
    goto LABEL_51;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x11u )
  {
    printk(&unk_3B7B47, *(unsigned __int8 *)(a1 + 3));
    if ( *(_BYTE *)(a1 + 4) )
      goto LABEL_50;
  }
  else
  {
    printk(&unk_3C9766, a2);
    if ( *(_BYTE *)(a1 + 4) )
      goto LABEL_50;
  }
LABEL_3:
  if ( !*(_BYTE *)(a1 + 48) )
    goto LABEL_4;
LABEL_51:
  printk(&unk_3CC0BA, *(unsigned __int8 *)(a1 + 49));
LABEL_4:
  if ( *(unsigned __int8 *)(a1 + 100) > 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_attrib_dump_eq__rs, "ipa3_attrib_dump_eq") )
      printk(&unk_3BACF8, "ipa3_attrib_dump_eq");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(
          v4,
          "ipa %s:%d num_offset_meq_128  Max %d passed value %d\n",
          "ipa3_attrib_dump_eq",
          999,
          2,
          *(unsigned __int8 *)(a1 + 100));
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(
          v5,
          "ipa %s:%d num_offset_meq_128  Max %d passed value %d\n",
          "ipa3_attrib_dump_eq",
          999,
          2,
          *(unsigned __int8 *)(a1 + 100));
    }
LABEL_41:
    result = 0xFFFFFFFFLL;
LABEL_42:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( !*(_BYTE *)(a1 + 100)
    || (printk(&unk_3B4A58, (unsigned int)*(char *)(a1 + 101)), *(unsigned __int8 *)(a1 + 100) < 2u)
    || (v16 = printk(&unk_3B4A58, (unsigned int)*(char *)(a1 + 134)), *(unsigned __int8 *)(a1 + 100) <= 2u) )
  {
    if ( *(unsigned __int8 *)(a1 + 20) > 2u )
    {
      if ( (unsigned int)__ratelimit(&ipa3_attrib_dump_eq__rs_279, "ipa3_attrib_dump_eq") )
        printk(&unk_3EEB59, "ipa3_attrib_dump_eq");
      v6 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v7 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v7 )
        {
          ipc_log_string(
            v7,
            "ipa %s:%d num_offset_meq_32  Max %d passed value %d\n",
            "ipa3_attrib_dump_eq",
            1016,
            2,
            *(unsigned __int8 *)(a1 + 20));
          v6 = ipa3_ctx;
        }
        v8 = *(_QWORD *)(v6 + 34160);
        if ( v8 )
          ipc_log_string(
            v8,
            "ipa %s:%d num_offset_meq_32  Max %d passed value %d\n",
            "ipa3_attrib_dump_eq",
            1016,
            2,
            *(unsigned __int8 *)(a1 + 20));
      }
      goto LABEL_41;
    }
    if ( !*(_BYTE *)(a1 + 20)
      || (printk(&unk_3EEB90, (unsigned int)*(char *)(a1 + 24)), *(unsigned __int8 *)(a1 + 20) <= 1u)
      || (v16 = printk(&unk_3EEB90, (unsigned int)*(char *)(a1 + 36)), *(unsigned __int8 *)(a1 + 20) <= 2u) )
    {
      if ( *(unsigned __int8 *)(a1 + 72) > 2u )
      {
        if ( (unsigned int)__ratelimit(&ipa3_attrib_dump_eq__rs_283, "ipa3_attrib_dump_eq") )
          printk(&unk_3E6057, "ipa3_attrib_dump_eq");
        v9 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v10 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v10 )
          {
            ipc_log_string(
              v10,
              "ipa %s:%d num_ihl_offset_meq_32  Max %d passed value %d\n",
              "ipa3_attrib_dump_eq",
              1029,
              2,
              *(unsigned __int8 *)(a1 + 72));
            v9 = ipa3_ctx;
          }
          v11 = *(_QWORD *)(v9 + 34160);
          if ( v11 )
            ipc_log_string(
              v11,
              "ipa %s:%d num_ihl_offset_meq_32  Max %d passed value %d\n",
              "ipa3_attrib_dump_eq",
              1029,
              2,
              *(unsigned __int8 *)(a1 + 72));
        }
        goto LABEL_41;
      }
      if ( !*(_BYTE *)(a1 + 72)
        || (printk(&unk_3B1E24, (unsigned int)*(char *)(a1 + 76)), *(unsigned __int8 *)(a1 + 72) <= 1u)
        || (v16 = printk(&unk_3B1E24, (unsigned int)*(char *)(a1 + 88)), *(unsigned __int8 *)(a1 + 72) <= 2u) )
      {
        if ( *(_BYTE *)(a1 + 167) )
          printk(&unk_3FADAA, (unsigned int)*(char *)(a1 + 168));
        if ( *(unsigned __int8 *)(a1 + 6) > 2u )
        {
          if ( (unsigned int)__ratelimit(&ipa3_attrib_dump_eq__rs_288, "ipa3_attrib_dump_eq") )
            printk(&unk_3FD993, "ipa3_attrib_dump_eq");
          v12 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v13 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v13 )
            {
              ipc_log_string(
                v13,
                "ipa %s:%d num_ihl_offset_range_16  Max %d passed value %d\n",
                "ipa3_attrib_dump_eq",
                1051,
                2,
                *(unsigned __int8 *)(a1 + 6));
              v12 = ipa3_ctx;
            }
            v14 = *(_QWORD *)(v12 + 34160);
            if ( v14 )
              ipc_log_string(
                v14,
                "ipa %s:%d num_ihl_offset_range_16  Max %d passed value %d\n",
                "ipa3_attrib_dump_eq",
                1051,
                2,
                *(unsigned __int8 *)(a1 + 6));
          }
          goto LABEL_41;
        }
        if ( !*(_BYTE *)(a1 + 6)
          || (printk(&unk_3D25D8, (unsigned int)*(char *)(a1 + 8)), *(unsigned __int8 *)(a1 + 6) <= 1u)
          || (v16 = printk(&unk_3D25D8, (unsigned int)*(char *)(a1 + 14)), *(unsigned __int8 *)(a1 + 6) <= 2u) )
        {
          if ( *(_BYTE *)(a1 + 62) )
          {
            printk(&unk_3E3701, (unsigned int)*(char *)(a1 + 64));
            if ( !*(_BYTE *)(a1 + 56) )
            {
LABEL_63:
              if ( !*(_BYTE *)(a1 + 50) )
                goto LABEL_64;
              goto LABEL_69;
            }
          }
          else if ( !*(_BYTE *)(a1 + 56) )
          {
            goto LABEL_63;
          }
          printk(&unk_3E6092, (unsigned int)*(char *)(a1 + 58));
          if ( !*(_BYTE *)(a1 + 50) )
          {
LABEL_64:
            if ( !*(_BYTE *)(a1 + 180) )
            {
LABEL_66:
              printk(&unk_3C36C1, a2);
              result = 0;
              goto LABEL_42;
            }
LABEL_65:
            printk(&unk_3FADD4, a2);
            goto LABEL_66;
          }
LABEL_69:
          printk(&unk_3C9772, *(unsigned int *)(a1 + 52));
          if ( !*(_BYTE *)(a1 + 180) )
            goto LABEL_66;
          goto LABEL_65;
        }
      }
    }
  }
  __break(0x5512u);
  return ipa3_start_read_memory_device(v16, a2, v17, v18);
}
