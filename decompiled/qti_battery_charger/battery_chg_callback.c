__int64 __fastcall battery_chg_callback(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w22
  __int64 v7; // x2
  unsigned int v8; // w3
  __int64 v9; // x2
  __int64 v10; // x8
  __int64 v11; // x9
  _QWORD *v12; // x8
  __int64 v13; // x9
  __int64 v14; // x11
  __int64 v15; // x12
  __int64 v16; // x9
  __int64 v17; // x11
  __int64 v18; // x12
  __int64 v19; // x9
  __int64 v20; // x11
  __int64 v21; // x12
  __int64 v22; // x9
  __int64 v23; // x11
  __int64 v24; // x12
  int v25; // w8
  _QWORD *v27; // x20
  __int64 v28; // x2
  void *v29; // x0
  __int64 v30; // x2
  void *v31; // x0
  unsigned int v32; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+28h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  down_read(a1 + 192);
  v6 = *(unsigned __int8 *)(a1 + 1144);
  up_read(a1 + 192);
  if ( v6 == 1 )
  {
    v8 = *(_DWORD *)(a2 + 8);
    switch ( v8 )
    {
      case 0u:
        printk(&unk_10A6A, "handle_message", v7);
        if ( a3 != 16 )
          goto LABEL_39;
        v30 = *(unsigned int *)(a2 + 12);
        *(_DWORD *)(a1 + 1056) = v30;
        printk(&unk_10FFB, "handle_message", v30);
        goto LABEL_40;
      case 1u:
      case 2u:
      case 3u:
      case 6u:
      case 8u:
      case 9u:
      case 0xAu:
      case 0xBu:
      case 0xCu:
      case 0xDu:
      case 0xEu:
      case 0xFu:
      case 0x10u:
      case 0x11u:
      case 0x12u:
      case 0x13u:
      case 0x14u:
      case 0x15u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
      case 0x19u:
      case 0x1Au:
      case 0x1Bu:
      case 0x1Cu:
      case 0x1Du:
      case 0x1Eu:
      case 0x1Fu:
      case 0x20u:
      case 0x21u:
      case 0x22u:
      case 0x23u:
      case 0x24u:
      case 0x25u:
      case 0x26u:
      case 0x27u:
      case 0x28u:
      case 0x29u:
      case 0x2Au:
      case 0x2Bu:
      case 0x2Cu:
      case 0x2Du:
      case 0x2Eu:
      case 0x2Fu:
      case 0x37u:
      case 0x38u:
      case 0x39u:
      case 0x3Au:
      case 0x3Bu:
      case 0x3Cu:
      case 0x3Du:
      case 0x3Eu:
      case 0x3Fu:
      case 0x41u:
      case 0x45u:
      case 0x46u:
        goto LABEL_63;
      case 4u:
      case 5u:
      case 0x36u:
      case 0x47u:
      case 0x48u:
        goto LABEL_40;
      case 7u:
        if ( a3 != 16 )
        {
          printk(&unk_10A38, "handle_notification", a3);
          break;
        }
        v25 = *(_DWORD *)(a2 + 12);
        if ( (unsigned __int16)v25 == 121 )
        {
          v32 = HIWORD(v25);
          raw_notifier_call_chain(&hboost_notifier, 0, &v32);
          break;
        }
        if ( v25 <= 51 )
        {
          if ( v25 != 48 )
          {
            if ( v25 != 50 )
              break;
            v27 = (_QWORD *)(a1 + 400);
            v28 = a1 + 592;
LABEL_50:
            queue_work_on(32, system_wq, v28);
            goto LABEL_59;
          }
LABEL_48:
          v27 = (_QWORD *)(a1 + 352);
          if ( *(int *)(a1 + 552) < 1 )
            goto LABEL_59;
          v28 = a1 + 1008;
          goto LABEL_50;
        }
        if ( v25 != 52 )
        {
          if ( v25 != 128 )
            break;
          goto LABEL_48;
        }
        v27 = (_QWORD *)(a1 + 448);
LABEL_59:
        if ( v27 )
        {
          if ( *v27 )
          {
            power_supply_changed(*v27);
            printk(&unk_FA60, "handle_notification", **(unsigned int **)(a1 + 424));
            pm_wakeup_dev_event(*(_QWORD *)a1, 50, 1);
            if ( *(_BYTE *)(a1 + 624) == 1 )
              queue_work_on(32, system_wq, a1 + 736);
          }
        }
        break;
      case 0x30u:
        if ( a3 == 144 )
        {
          v12 = *(_QWORD **)(a1 + 360);
          if ( v12 )
          {
            v13 = *(_QWORD *)(a2 + 40);
            v14 = *(_QWORD *)(a2 + 16);
            v15 = *(_QWORD *)(a2 + 24);
            v12[2] = *(_QWORD *)(a2 + 32);
            v12[3] = v13;
            *v12 = v14;
            v12[1] = v15;
            v16 = *(_QWORD *)(a2 + 72);
            v17 = *(_QWORD *)(a2 + 48);
            v18 = *(_QWORD *)(a2 + 56);
            v12[6] = *(_QWORD *)(a2 + 64);
            v12[7] = v16;
            v12[4] = v17;
            v12[5] = v18;
            v19 = *(_QWORD *)(a2 + 104);
            v20 = *(_QWORD *)(a2 + 80);
            v21 = *(_QWORD *)(a2 + 88);
            v12[10] = *(_QWORD *)(a2 + 96);
            v12[11] = v19;
            v12[8] = v20;
            v12[9] = v21;
            v22 = *(_QWORD *)(a2 + 136);
            v23 = *(_QWORD *)(a2 + 112);
            v24 = *(_QWORD *)(a2 + 120);
            v12[14] = *(_QWORD *)(a2 + 128);
            v12[15] = v22;
            v12[12] = v23;
            v12[13] = v24;
            *(_BYTE *)(a1 + 1077) = strcmp(*(const char **)(a1 + 360), "Debug_Board") == 0;
            goto LABEL_40;
          }
        }
        if ( a3 != 24 )
        {
LABEL_77:
          printk(&unk_FEEC, "validate_message", a3);
          goto LABEL_39;
        }
        if ( *(_DWORD *)(a2 + 20) )
        {
LABEL_36:
          if ( (unsigned int)__ratelimit(&validate_message__rs, "validate_message") )
            printk(&unk_1065D, "validate_message", *(unsigned int *)(a2 + 8));
          *(_BYTE *)(a1 + 1165) = 1;
          goto LABEL_39;
        }
        v10 = *(unsigned int *)(a2 + 12);
        if ( (unsigned int)v10 >= *(_DWORD *)(a1 + 384) )
          goto LABEL_39;
        v11 = *(_QWORD *)(a1 + 376);
LABEL_53:
        *(_DWORD *)(v11 + 4 * v10) = *(_DWORD *)(a2 + 16);
        goto LABEL_40;
      case 0x31u:
      case 0x33u:
      case 0x35u:
        if ( a3 != 24 )
          goto LABEL_77;
        if ( !*(_DWORD *)(a2 + 20) )
          goto LABEL_40;
        goto LABEL_36;
      case 0x32u:
        if ( a3 != 24 )
          goto LABEL_77;
        if ( *(_DWORD *)(a2 + 20) )
          goto LABEL_36;
        v10 = *(unsigned int *)(a2 + 12);
        if ( (unsigned int)v10 >= *(_DWORD *)(a1 + 432) )
          goto LABEL_39;
        v11 = *(_QWORD *)(a1 + 424);
        goto LABEL_53;
      case 0x34u:
        if ( a3 != 24 )
          goto LABEL_77;
        if ( *(_DWORD *)(a2 + 20) )
          goto LABEL_36;
        v10 = *(unsigned int *)(a2 + 12);
        if ( (unsigned int)v10 >= *(_DWORD *)(a1 + 480) )
          goto LABEL_39;
        v11 = *(_QWORD *)(a1 + 472);
        goto LABEL_53;
      case 0x40u:
        if ( a3 != 16 )
        {
          v31 = &unk_108EE;
          goto LABEL_71;
        }
        if ( *(_DWORD *)(a2 + 12) == 1 )
          *(_BYTE *)(a1 + 1078) = 1;
        goto LABEL_40;
      case 0x42u:
        if ( a3 != 16 )
        {
          v31 = &unk_1031D;
          goto LABEL_71;
        }
        v9 = *(unsigned int *)(a2 + 12);
        if ( (_DWORD)v9 == 1 )
        {
          complete(a1 + 320);
          goto LABEL_39;
        }
        v29 = &unk_116AB;
        goto LABEL_75;
      case 0x43u:
        if ( a3 != 16 )
        {
          v31 = &unk_11020;
          goto LABEL_71;
        }
        if ( *(_DWORD *)(a2 + 12) == 1 )
          complete(a1 + 288);
        goto LABEL_39;
      case 0x44u:
        if ( a3 == 16 )
        {
          *(_DWORD *)(a1 + 1080) = *(_DWORD *)(a2 + 12);
          goto LABEL_40;
        }
        v31 = &unk_1133B;
LABEL_71:
        printk(v31, "handle_message", a3);
        goto LABEL_39;
      default:
        if ( v8 == 256 )
        {
          if ( a3 == 16 )
          {
            printk(&unk_10781, "handle_message", v7);
            goto LABEL_40;
          }
        }
        else if ( v8 == 257 )
        {
          if ( a3 == 272 )
            printk(&unk_1012D, "handle_message", a2 + 12);
          else
            printk(&unk_10B87, "handle_message", v7);
        }
        else
        {
LABEL_63:
          v29 = &unk_FFFB;
          v9 = v8;
LABEL_75:
          printk(v29, "handle_message", v9);
        }
LABEL_39:
        if ( *(_BYTE *)(a1 + 1165) != 1 )
          break;
LABEL_40:
        complete(a1 + 256);
        break;
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
