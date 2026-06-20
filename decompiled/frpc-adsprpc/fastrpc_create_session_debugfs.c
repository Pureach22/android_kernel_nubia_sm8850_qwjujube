__int64 __fastcall fastrpc_create_session_debugfs(__int64 result)
{
  int v1; // w23
  __int64 v2; // x19
  __int64 v3; // x20
  unsigned int v10; // w8
  unsigned __int64 StatusReg; // x21
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned int v14; // w22
  size_t v15; // x0
  unsigned int v16; // w9
  int v17; // w8
  bool v18; // cc
  unsigned int v19; // w10
  int v20; // w9
  int v21; // w10
  unsigned int v22; // w12
  unsigned __int64 file; // x0
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x24
  _BYTE string[15]; // [xsp+18h] [xbp-18h] BYREF
  char v28; // [xsp+27h] [xbp-9h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v2 = result;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = qword_27538;
  _X10 = (unsigned int *)(result + 216);
  __asm { PRFM            #0x11, [X10] }
  while ( 1 )
  {
    v10 = __ldxr(_X10);
    if ( v10 )
      break;
    if ( !__stlxr(1u, _X10) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( !v10 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = *(_QWORD *)(StatusReg + 2320);
    v13 = *(_QWORD *)(StatusReg + 2327);
    v28 = 0;
    *(_QWORD *)string = v12;
    *(_QWORD *)&string[7] = v13;
    if ( v3 )
    {
      v14 = **(_DWORD **)(result + 128);
      v15 = strnlen(string, 0x10u);
      if ( v15 >= 0x11 )
      {
        _fortify_panic(2);
      }
      else if ( v15 != 16 )
      {
        v16 = *(_DWORD *)(StatusReg + 1800);
        if ( v16 )
        {
          v17 = 0;
          do
          {
            v18 = v16 > 9;
            ++v17;
            v16 /= 0xAu;
          }
          while ( v18 );
          v19 = *(_DWORD *)(v2 + 244);
          if ( v19 )
          {
LABEL_14:
            v20 = 0;
            do
            {
              v18 = v19 > 9;
              ++v20;
              v19 /= 0xAu;
            }
            while ( v18 );
            if ( v14 )
              goto LABEL_17;
            goto LABEL_22;
          }
        }
        else
        {
          v17 = 1;
          v19 = *(_DWORD *)(v2 + 244);
          if ( v19 )
            goto LABEL_14;
        }
        v20 = 1;
        if ( v14 )
        {
LABEL_17:
          v21 = 0;
          v22 = v14;
          do
          {
            v18 = v22 > 9;
            ++v21;
            v22 /= 0xAu;
          }
          while ( v18 );
LABEL_23:
          v1 = v15 + v17 + v20 + v21 + 4;
          result = _kmalloc_noprof(v1, 3520);
          *(_QWORD *)(v2 + 232) = result;
          if ( !result )
            goto LABEL_2;
          goto LABEL_24;
        }
LABEL_22:
        v21 = 1;
        goto LABEL_23;
      }
      _fortify_panic(4);
      v26 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &fastrpc_create_session_debugfs__alloc_tag;
      result = _kmalloc_noprof(v1, 3520);
      *(_QWORD *)(StatusReg + 80) = v26;
      *(_QWORD *)(v2 + 232) = result;
      if ( !result )
        goto LABEL_2;
LABEL_24:
      snprintf(
        (char *)result,
        v1,
        "%.10s%s%d%s%d%s%d",
        string,
        "_",
        *(_DWORD *)(StatusReg + 1800),
        "_",
        *(_DWORD *)(v2 + 244),
        "_",
        v14);
      file = debugfs_create_file(*(_QWORD *)(v2 + 232), 420, v3, v2, &fastrpc_debugfs_fops);
      *(_QWORD *)(v2 + 224) = file;
      if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_24E38, string, "fastrpc_create_session_debugfs", *(_QWORD *)(v2 + 232), v24, v25);
        *(_QWORD *)(v2 + 224) = 0;
      }
      result = kfree(*(_QWORD *)(v2 + 232));
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
