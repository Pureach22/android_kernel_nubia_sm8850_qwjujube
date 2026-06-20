__int64 __fastcall hfi_adapter_unpack_cmd_buf(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x9
  unsigned int header_info; // w0
  int v6; // w27
  unsigned int v7; // w22
  unsigned int v8; // w21
  __int64 **v9; // x28
  __int64 *i; // x26
  void (__fastcall **v11)(__int64, __int64, __int64, __int64); // x4
  __int64 v12; // x0
  __int64 v13; // x1
  void (__fastcall *v14)(__int64, __int64, __int64, __int64); // x8
  __int64 v15; // x2
  __int64 v16; // x3
  _QWORD *v17; // x10
  unsigned int v24; // w12
  _QWORD *v25; // x11
  __int64 v27; // [xsp+8h] [xbp-48h] BYREF
  __int64 v28; // [xsp+10h] [xbp-40h]
  __int64 v29; // [xsp+18h] [xbp-38h]
  __int64 v30; // [xsp+20h] [xbp-30h]
  _QWORD v31[2]; // [xsp+28h] [xbp-28h] BYREF
  __int64 v32; // [xsp+38h] [xbp-18h] BYREF
  __int64 v33; // [xsp+40h] [xbp-10h]
  __int64 v34; // [xsp+48h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v31[0] = 0;
  v31[1] = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  if ( a1 && a2 && a1[15] )
  {
    v4 = *(_QWORD *)(a2 + 80);
    v32 = *(_QWORD *)(a2 + 64);
    LODWORD(v33) = v4;
    header_info = hfi_unpacker_get_header_info(&v32, v31);
    if ( header_info )
    {
      v8 = header_info;
      printk(&unk_279B90, "hfi_adapter_unpack_cmd_buf");
    }
    else
    {
      v6 = v31[0];
      if ( LODWORD(v31[0]) )
      {
        v7 = 0;
        v8 = 0;
        v9 = (__int64 **)(a1 + 10);
        while ( 1 )
        {
          ++v7;
          v29 = 0;
          v30 = 0;
          v27 = 0;
          v28 = 0;
          if ( !(unsigned int)hfi_unpacker_get_packet_info(&v32, v7, &v27) )
            break;
          printk(&unk_25E068, "hfi_adapter_unpack_cmd_buf");
LABEL_8:
          if ( v7 == v6 )
            goto LABEL_23;
        }
        for ( i = *v9; ; i = (__int64 *)*i )
        {
          if ( i == (__int64 *)v9 )
            goto LABEL_8;
          if ( i )
          {
            v11 = (void (__fastcall **)(__int64, __int64, __int64, __int64))i[3];
            if ( !v11 )
            {
              printk(&unk_22A690, "hfi_adapter_unpack_cmd_buf");
LABEL_12:
              v8 = -1;
              continue;
            }
            if ( HIDWORD(v28) == *((_DWORD *)i + 4) )
            {
              v13 = (unsigned int)v27;
              v12 = HIDWORD(v27);
              v14 = *v11;
              v15 = v30;
              v16 = HIDWORD(v29);
              if ( *((_DWORD *)*v11 - 1) != 1004425291 )
                __break(0x8228u);
              v14(v12, v13, v15, v16);
              if ( (unsigned int)v28 >= 2 )
              {
                printk(&unk_2767E0, "hfi_adapter_unpack_cmd_buf");
                goto LABEL_12;
              }
            }
          }
        }
      }
      v8 = 0;
LABEL_23:
      mutex_lock(a1[15] + 368LL);
      v17 = (_QWORD *)a1[8];
      if ( v17 != a1 + 8 )
      {
        do
        {
          v25 = (_QWORD *)*v17;
          if ( v17 != (_QWORD *)&unk_68 && *((_DWORD *)v17 - 13) == *(_DWORD *)(a2 + 52) )
          {
            _X10 = (unsigned int *)(v17 + 6);
            __asm { PRFM            #0x11, [X10] }
            do
              v24 = __ldxr(_X10);
            while ( __stxr(v24 + 1, _X10) );
          }
          v17 = v25;
        }
        while ( v25 != a1 + 8 );
      }
      mutex_unlock(a1[15] + 368LL);
    }
  }
  else
  {
    printk(&unk_22DBEA, "hfi_adapter_unpack_cmd_buf");
    v8 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
