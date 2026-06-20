__int64 __fastcall get_module_ids(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x0
  __int64 v8; // x22
  __int64 v9; // x23
  int v10; // w26
  __int64 v11; // x0
  unsigned int (__fastcall *v12)(__int64, int *, __int64, __int64, __int64, __int64); // x8
  __int64 v13; // x19
  __int64 v15; // [xsp+8h] [xbp-38h]
  int v16; // [xsp+10h] [xbp-30h] BYREF
  _QWORD v17[4]; // [xsp+14h] [xbp-2Ch] BYREF
  int v18; // [xsp+34h] [xbp-Ch]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  v7 = _kmalloc_cache_noprof(debugfs_attr_write, 3520, 2048);
  v8 = v7;
  if ( v7 )
  {
    v15 = a3;
    v9 = (int)scnprintf(v7, 30, "Module ID Module Name\n");
    v10 = 0;
    while ( 1 )
    {
      v11 = ph;
      v12 = *(unsigned int (__fastcall **)(__int64, int *, __int64, __int64, __int64, __int64))(ops + 8);
      v16 = v10;
      if ( *((_DWORD *)v12 - 1) != 1134762728 )
        __break(0x8228u);
      if ( v12(v11, &v16, 0x435055435043544CLL, 5, 4, 40) )
        break;
      v9 += (int)scnprintf(v8 + v9, 2048 - v9, "%9d %s\n", v16, (const char *)v17);
      ++v10;
      if ( !v18 )
        goto LABEL_7;
    }
    printk(&unk_8666);
LABEL_7:
    v13 = simple_read_from_buffer(a2, v15, a4, v8, v9);
    kfree(v8);
  }
  else
  {
    v13 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v13;
}
