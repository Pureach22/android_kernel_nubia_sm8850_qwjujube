size_t __fastcall hw_fence_dbg_dump_table_wr(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  size_t v5; // x19
  __int64 v7; // x20
  unsigned int v8; // w0
  __int64 v9; // x9
  __int64 v11; // [xsp+0h] [xbp-30h] BYREF
  __int64 v12; // [xsp+8h] [xbp-28h] BYREF
  char s[8]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v14; // [xsp+18h] [xbp-18h]
  __int64 v15; // [xsp+20h] [xbp-10h]
  __int64 v16; // [xsp+28h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v12 = 0;
  v14 = 0;
  v15 = 0;
  *(_QWORD *)s = 0;
  if ( !a1 || (v4 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    printk(&unk_2A0F5, "hw_fence_dbg_dump_table_wr", 1121, v3, a1);
    v5 = -22;
    goto LABEL_11;
  }
  v5 = a3;
  if ( a3 >= 0x18 )
  {
    printk(&unk_26A1D, "hw_fence_dbg_dump_table_wr", 1127, v3, a3);
  }
  else
  {
    v7 = v3;
    _check_object_size(s, a3, 0);
    if ( !inline_copy_from_user((__int64)s, a2, v5) )
    {
      s[v5] = 0;
      v8 = sscanf(s, "%llu %llu", &v12, &v11);
      if ( v8 == 1 )
      {
        *(_BYTE *)(v4 + 488) = 0;
        *(_QWORD *)(v4 + 496) = 0;
        *(_QWORD *)(v4 + 504) = 0;
        goto LABEL_11;
      }
      if ( v8 == 2 )
      {
        v9 = v11;
        *(_QWORD *)(v4 + 496) = v12;
        *(_QWORD *)(v4 + 504) = v9;
        *(_BYTE *)(v4 + 488) = 1;
        goto LABEL_11;
      }
      printk(&unk_23955, "hw_fence_dbg_dump_table_wr", 1148, v7, v8);
    }
  }
  v5 = -14;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v5;
}
