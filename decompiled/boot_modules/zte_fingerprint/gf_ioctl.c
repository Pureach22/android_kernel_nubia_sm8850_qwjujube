__int64 __fastcall gf_ioctl(int a1, int a2, unsigned __int64 a3)
{
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x10
  unsigned __int64 v5; // x9
  __int64 result; // x0
  void *v7; // x0
  int v8; // w19
  void *v9; // x0
  int v10; // w20
  unsigned __int64 v11; // x21
  unsigned __int64 v12; // x19
  unsigned int v13; // w19
  int v14; // w19
  __int64 v15; // x0
  void *v16; // x0
  int v17; // w8
  char v18[4]; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v18[0] = 25;
  if ( (a2 & 0xFF00) != 0x6700 )
    goto LABEL_47;
  v20 = 0;
  v21[0] = 0;
  if ( a2 < 0 || (unsigned int)a2 >> 30 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = *(_QWORD *)StatusReg, v5 = a3, (v4 & 0x4000000) != 0) )
      v5 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( 0x8000000000LL - (unsigned __int64)(HIWORD(a2) & 0x3FFF) < v5 )
      goto LABEL_8;
  }
  if ( !(_BYTE)word_83E0 )
  {
    if ( (unsigned int)(a2 - 26375) <= 1 )
    {
      v10 = a2;
      v11 = a3;
      printk(&unk_9531);
      a3 = v11;
      a2 = v10;
      goto LABEL_10;
    }
    printk(&unk_874E);
LABEL_47:
    result = -19;
    goto LABEL_48;
  }
LABEL_10:
  result = 0;
  if ( a2 <= 26374 )
  {
    if ( a2 > 26370 )
    {
      if ( a2 == 26374 )
        goto LABEL_48;
      if ( a2 == 26371 )
      {
        v15 = printk(&unk_89E4);
        gf_enable_irq(v15);
        goto LABEL_56;
      }
      if ( a2 != 26372 )
        goto LABEL_49;
      printk(&unk_8CD0);
      gf_disable_irq(&gf);
      goto LABEL_56;
    }
    if ( a2 > 26368 )
    {
      if ( a2 != 26369 )
      {
        printk(&unk_8CFA);
        gf_hw_reset(&gf, 5);
        goto LABEL_56;
      }
      v7 = &unk_93AF;
    }
    else
    {
      if ( a2 == -2147391744 )
      {
        v12 = a3;
        printk(&unk_8781);
        if ( inline_copy_to_user(v12, v18) )
          result = -14;
        else
          result = 0;
        goto LABEL_48;
      }
      if ( a2 != -2147391733 )
        goto LABEL_49;
      v7 = &unk_86AF;
    }
LABEL_55:
    printk(v7);
    goto LABEL_56;
  }
  if ( a2 > 1074030340 )
  {
    if ( a2 <= 1074030349 )
    {
      if ( a2 == 1074030341 )
        goto LABEL_48;
      goto LABEL_49;
    }
    switch ( a2 )
    {
      case 1074030350:
        v14 = a3;
        printk(&unk_9558);
        if ( !inline_copy_from_user((int)&v19, v14, 4u) )
        {
          nav_event_input(v19);
          goto LABEL_56;
        }
        v16 = &unk_9447;
        break;
      case 1074292489:
        if ( !inline_copy_from_user((int)&v20, a3, 8u) )
        {
          switch ( (_DWORD)v20 )
          {
            case 1:
              v13 = 102;
              break;
            case 5:
              v13 = 212;
              break;
            case 2:
              v13 = 116;
              break;
            default:
              v13 = v20;
              break;
          }
          printk(&unk_8DCD);
          v17 = v20;
          if ( (_DWORD)v20 == 5 || (_DWORD)v20 == 2 )
          {
            if ( HIDWORD(v20) != 1 )
              goto LABEL_56;
            input_event(qword_83A0, 1, v13, 1);
            input_event(qword_83A0, 0, 0, 0);
            input_event(qword_83A0, 1, v13, 0);
            input_event(qword_83A0, 0, 0, 0);
            v17 = v20;
          }
          if ( v17 == 1 )
          {
            input_event(qword_83A0, 1, v13, HIDWORD(v20) != 0);
            input_event(qword_83A0, 0, 0, 0);
          }
          goto LABEL_56;
        }
        v16 = &unk_98EE;
        break;
      case 1074292493:
        v8 = a3;
        printk(&unk_9667);
        if ( inline_copy_from_user((int)v21, v8, 8u) )
        {
LABEL_8:
          result = -14;
          goto LABEL_48;
        }
        printk(&unk_88A7);
        printk(&unk_8A58);
        v9 = &unk_8D1E;
        goto LABEL_50;
      default:
LABEL_49:
        v9 = &unk_968F;
LABEL_50:
        printk(v9);
        goto LABEL_56;
    }
    printk(v16);
    result = -14;
    goto LABEL_48;
  }
  if ( a2 > 26377 )
  {
    if ( a2 != 26378 )
    {
      if ( a2 != 26380 )
        goto LABEL_49;
      printk(&unk_937E);
      gf_cleanup(&gf);
LABEL_56:
      result = 0;
      goto LABEL_48;
    }
    v7 = &unk_8EA7;
    goto LABEL_55;
  }
  if ( a2 == 26375 )
  {
    printk(&unk_9112);
    if ( (unsigned __int8)word_83E0 == 1 )
      printk(&unk_92C1);
    else
      gf_power_on(&gf);
    result = 0;
    LOBYTE(word_83E0) = 1;
  }
  else
  {
    if ( a2 != 26376 )
      goto LABEL_49;
    printk(&unk_8D76);
    if ( (_BYTE)word_83E0 )
      gf_power_off(&gf);
    else
      printk(&unk_8F94);
    result = 0;
    LOBYTE(word_83E0) = 0;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
