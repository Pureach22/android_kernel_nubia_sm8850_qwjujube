__int64 __fastcall goodix_fb_state_chg_callback(int a1, _DWORD *a2, __int64 a3)
{
  void *v3; // x0
  __int64 result; // x0
  char v8; // w8
  char v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  if ( a2 && a3 )
  {
    if ( *(_BYTE *)(a3 + 112) )
    {
      result = printk(&unk_9855);
      if ( a1 != 1 )
        goto LABEL_8;
      if ( *a2 == 1 )
      {
        printk(&unk_8BC6);
        *(_BYTE *)(a3 + 113) = 1;
        printk(&unk_909F);
        v8 = 2;
      }
      else
      {
        if ( *a2 != 2 )
        {
          v3 = &unk_8646;
          goto LABEL_6;
        }
        printk(&unk_9257);
        *(_BYTE *)(a3 + 113) = 0;
        printk(&unk_85F4);
        v8 = 3;
      }
      v9[0] = v8;
      result = sendnlmsg(v9);
      goto LABEL_8;
    }
    v3 = &unk_85B0;
  }
  else
  {
    v3 = &unk_93D2;
  }
LABEL_6:
  result = printk(v3);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
