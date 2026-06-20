__int64 __fastcall synx_ioctl(__int64 a1, int a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 v6; // x19
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 result; // x0
  int v12; // w4
  bool v13; // zf
  int v14; // w20
  int fence; // w0
  int v16; // w0
  __int64 v17; // x4
  unsigned __int64 v18; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 32);
  v19[1] = 0;
  v20 = 0;
  v18 = v6;
  v19[0] = 0;
  if ( a2 == -1072139390 )
  {
    if ( inline_copy_from_user((int)v19, a3, 0x18u) )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2B4EB, &unk_29207, "synx_ioctl", 3535, v9, v10);
      result = -14;
      goto LABEL_50;
    }
    if ( !v20 )
    {
LABEL_17:
      result = -22;
      goto LABEL_50;
    }
    v12 = v19[0];
    v13 = v6 >= 0xFFFFFFFFFFFFF001LL || v6 == 0;
    if ( v13 && LODWORD(v19[0]) != 14 )
    {
      if ( (synx_debug & 1) != 0 )
      {
        printk(&unk_27357, &unk_29207, "synx_ioctl", 3543, LODWORD(v19[0]), v10);
        result = -22;
        goto LABEL_50;
      }
      goto LABEL_17;
    }
    if ( (synx_debug & 0x10) != 0 )
    {
      printk(&unk_29501, "verb", "synx_ioctl", 3548, LODWORD(v19[0]), *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800));
      v12 = v19[0];
    }
    v14 = -22;
    switch ( v12 )
    {
      case 0:
        fence = synx_handle_create(v19, v6);
        goto LABEL_47;
      case 1:
        fence = synx_handle_release(v19, v6);
        goto LABEL_47;
      case 2:
        fence = synx_handle_signal(v19, v6);
        goto LABEL_47;
      case 3:
        fence = synx_handle_merge(v19, v6);
        goto LABEL_47;
      case 4:
        fence = synx_handle_async_wait(v19, v6);
        goto LABEL_47;
      case 5:
        fence = synx_handle_cancel_async_wait(v19, v6);
        goto LABEL_47;
      case 6:
        v14 = synx_handle_wait(v19, v6);
        if ( !inline_copy_to_user(a3, v19, 24) )
          break;
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2B4EB, &unk_29207, "synx_ioctl", 3590, v17, v10);
        v14 = -14;
        if ( (synx_debug & 0x10) != 0 )
          goto LABEL_42;
        goto LABEL_49;
      case 7:
        fence = synx_handle_bind(v19, v6);
        goto LABEL_47;
      case 9:
        fence = synx_handle_getstatus(v19, v6);
        goto LABEL_47;
      case 10:
        fence = synx_handle_import(v19, v6);
        goto LABEL_47;
      case 12:
        fence = synx_handle_import_arr(v19, v6);
        goto LABEL_47;
      case 13:
        fence = synx_handle_get_fence(v19, v6);
        goto LABEL_47;
      case 14:
        v16 = synx_handle_initialize(v19, &v18);
        goto LABEL_41;
      case 15:
        fence = synx_handle_recover(v19, v6);
        goto LABEL_47;
      case 16:
        fence = synx_handle_release_n(v19, v6);
        goto LABEL_47;
      case 17:
        v16 = synx_handle_initialize_v3(v19, &v18);
LABEL_41:
        v14 = v16;
        *(_QWORD *)(a1 + 32) = v18;
        if ( (synx_debug & 0x10) != 0 )
          goto LABEL_42;
        goto LABEL_49;
      case 18:
        fence = synx_handle_import_v2(v19, v6);
        goto LABEL_47;
      case 19:
        fence = synx_handle_import_arr_v2(v19, v6);
        goto LABEL_47;
      case 20:
        fence = synx_handle_merge_n(v19, v6);
LABEL_47:
        v14 = fence;
        break;
      default:
        break;
    }
    if ( (synx_debug & 0x10) != 0 )
LABEL_42:
      printk(&unk_29763, "verb", "synx_ioctl", 3627, (unsigned int)v14, v10);
LABEL_49:
    result = v14;
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_26069, &unk_29207, "synx_ioctl", 3528, a5, a6);
    result = -515;
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
