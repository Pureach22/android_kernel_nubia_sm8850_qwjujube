__int64 __fastcall trig_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x21
  unsigned int v7; // w8
  char v8; // w9
  unsigned int v9; // w11
  char v10; // w10
  _BYTE *v11; // x11
  char v12; // w8
  char v13; // w8
  __int64 v14; // [xsp+30h] [xbp-30h] BYREF
  __int64 v15; // [xsp+38h] [xbp-28h] BYREF
  __int64 v16; // [xsp+40h] [xbp-20h] BYREF
  __int64 v17; // [xsp+48h] [xbp-18h] BYREF
  int v18; // [xsp+50h] [xbp-10h] BYREF
  __int64 v19; // [xsp+58h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v18 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  if ( sscanf(
         s,
         "%u %u %u %u %u %u %u %u %u",
         &v14,
         (char *)&v14 + 4,
         &v15,
         (char *)&v15 + 4,
         &v16,
         (char *)&v16 + 4,
         &v17,
         (char *)&v17 + 4,
         &v18) == 9 )
  {
    printk(&unk_162A7, "haptic_hv", 2202, "trig_store");
    if ( (unsigned int)(v14 - 4) <= 0xFFFFFFFC )
    {
      printk(&unk_16872, "haptic_hv", 2204, "trig_store");
    }
    else
    {
      v7 = v14 - 1;
      if ( (_DWORD)v14 == 1 && *(_BYTE *)(v5 + 1047) == 1 )
      {
        printk(&unk_146F2, "haptic_hv", 2208, "trig_store");
      }
      else if ( (*(_BYTE *)(v5 - 162) & 1) != 0 )
      {
        v8 = v16;
        v9 = *(unsigned __int8 *)(v5 + 948);
        if ( (unsigned int)v16 > v9 || (v10 = v17, (unsigned int)v17 > v9) )
        {
          printk(&unk_16034, "haptic_hv", 2217, "trig_store");
        }
        else
        {
          LODWORD(v14) = v14 - 1;
          v11 = (_BYTE *)(v5 + 13LL * v7);
          v11[1343] = BYTE4(v14);
          v11[1344] = v15;
          v12 = BYTE4(v15);
          v11[1347] = v8;
          v11[1345] = v12;
          v13 = BYTE4(v16);
          v11[1348] = v10;
          v11[1346] = v13;
          v11[1341] = BYTE4(v17);
          v11[1342] = v18;
          mutex_lock(v5 + 584);
          switch ( (_DWORD)v14 )
          {
            case 2:
              aw8693x_trig3_param_config(v5 - 168);
              break;
            case 1:
              aw8693x_trig2_param_config(v5 - 168);
              break;
            case 0:
              aw8693x_trig1_param_config(v5 - 168);
              break;
          }
          mutex_unlock(v5 + 584);
        }
      }
      else
      {
        printk(&unk_16977, "haptic_hv", 2212, "trig_store");
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
