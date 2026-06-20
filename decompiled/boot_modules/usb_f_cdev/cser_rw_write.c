__int64 __fastcall cser_rw_write(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x19
  unsigned int v7; // w0
  __int64 v8; // x3
  int v9; // w8
  int v10; // w9
  unsigned int v11; // w0
  __int64 v12; // x2
  void *v14; // x0
  _BYTE v15[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v15[0] = 0;
  v5 = *(_QWORD *)(v4 + 128);
  if ( v5 == -1200 )
  {
    printk(&unk_92F2, "cser_rw_write", a3, a4);
    v6 = -22;
  }
  else if ( *(_BYTE *)(v5 + 1560) == 1 )
  {
    v6 = a3;
    if ( a2 )
    {
      v7 = kstrtou8_from_user(a2, a3, 0, v15);
      if ( v7 )
      {
        v12 = v7;
        v14 = &unk_8FC9;
LABEL_16:
        printk(v14, "cser_rw_write", v12, v8);
        goto LABEL_13;
      }
      v9 = v15[0];
      v10 = v15[0] != 0;
      if ( *(unsigned __int8 *)(v5 + 1608) != v10 )
      {
        *(_BYTE *)(v5 + 1608) = v10;
        if ( v9 )
        {
          if ( *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(v5 + 1248) + 48LL) + 72LL) >= 5u
            && (*(_BYTE *)(v5 + 1192) & 1) != 0 )
          {
            v12 = 0xFFFFFFFFLL;
LABEL_18:
            v14 = &unk_9376;
            goto LABEL_16;
          }
          v11 = usb_gadget_wakeup();
          v12 = v11;
          if ( v11 != 0 && v11 < 0xFFFFFFF0 || ((1 << (v11 + 16)) & 0x10021) == 0 )
            goto LABEL_18;
        }
      }
    }
  }
  else
  {
    v6 = -19;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v6;
}
