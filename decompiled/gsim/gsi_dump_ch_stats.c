__int64 __fastcall gsi_dump_ch_stats(__int64 result, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x19
  __int64 v4; // x2
  __int64 v5; // x2
  __int64 v6; // x9
  _QWORD *v7; // x8
  _QWORD *v8; // x19
  __int64 v9; // x2
  __int64 v10; // x2
  __int64 v11; // x2
  __int64 v12; // x2
  __int64 v13; // x1
  __int64 v14; // x2

  if ( *(_BYTE *)(result + 296) == 1 )
  {
    v3 = (_QWORD *)result;
    printk(&unk_2AC45, *(unsigned __int8 *)(result + 8), a3);
    printk(&unk_2D849, v3[41], v3[42]);
    printk(&unk_2AF81, v3[43], v3[44]);
    printk(&unk_2E093, v3[46], v4);
    printk(&unk_2D1FF, v3[47], v3[48]);
    v6 = v3[26];
    v7 = v3;
    if ( v6 )
    {
      printk(&unk_2BBCE, *(_QWORD *)(v6 + 320), v5);
      v7 = v3;
    }
    v8 = v7;
    printk(&unk_2D861, v7[49], v5);
    printk(&unk_2C342, v8[50], v9);
    printk(&unk_2BBDF, v8[51], v10);
    printk(&unk_2DB56, v8[52], v11);
    printk(&unk_2C82E, v8[53], v12);
    return printk(&unk_2BBF2, v13, v14);
  }
  return result;
}
