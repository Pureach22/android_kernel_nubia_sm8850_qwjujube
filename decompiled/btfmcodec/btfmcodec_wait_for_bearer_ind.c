__int64 __fastcall btfmcodec_wait_for_bearer_ind(__int64 a1)
{
  _QWORD *v2; // x21
  __int64 result; // x0
  int v4; // w8
  void *v5; // x0
  unsigned __int64 v6; // x20
  _QWORD *v7; // x8
  bool v8; // zf
  _QWORD v9[6]; // [xsp+0h] [xbp-30h] BYREF

  v9[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)(a1 + 747) && (v2 = (_QWORD *)(a1 + 344), *(_QWORD *)(a1 + 344) == a1 + 344) )
  {
    memset(v9, 0, 40);
    init_wait_entry(v9, 0);
    result = prepare_to_wait_event(a1 + 624, v9, 1);
    if ( *(_BYTE *)(a1 + 747) )
    {
      v6 = 6250;
LABEL_13:
      if ( v6 <= 1 )
        v6 = 1;
    }
    else
    {
      v6 = 6250;
      while ( 1 )
      {
        v7 = (_QWORD *)*v2;
        if ( v6 )
          v8 = 1;
        else
          v8 = v7 == v2;
        if ( !v8 )
          v6 = 1;
        if ( v7 != v2 || !v6 )
          break;
        if ( result )
          goto LABEL_4;
        v6 = schedule_timeout(v6);
        result = prepare_to_wait_event(a1 + 624, v9, 1);
        if ( *(_BYTE *)(a1 + 747) )
          goto LABEL_13;
      }
    }
    finish_wait(a1 + 624, v9);
    result = v6;
  }
  else
  {
    result = 6250;
  }
LABEL_4:
  if ( *(_QWORD *)(a1 + 344) != a1 + 344 )
  {
    printk(&unk_D0D2, "btfmcodec_wait_for_bearer_ind");
LABEL_31:
    result = 0xFFFFFFFFLL;
    goto LABEL_32;
  }
  if ( (_DWORD)result )
  {
    v4 = *(unsigned __int8 *)(a1 + 747);
    switch ( v4 )
    {
      case 1:
        result = 0;
        break;
      case 3:
        v5 = &unk_BEE1;
        goto LABEL_30;
      case 2:
        v5 = &unk_D41D;
LABEL_30:
        printk(v5, "btfmcodec_wait_for_bearer_ind");
        goto LABEL_31;
    }
  }
  else
  {
    printk(&unk_BEB2, "btfmcodec_wait_for_bearer_ind");
    result = 4294967293LL;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
