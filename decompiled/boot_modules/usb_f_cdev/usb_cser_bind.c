__int64 __fastcall usb_cser_bind(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x21
  __int64 v3; // x22
  __int64 result; // x0
  char v7; // w8
  _QWORD *v8; // x0
  _QWORD *v9; // x0
  _QWORD *v10; // x0
  __int64 v11; // x0
  char v12; // w8
  __int64 v13; // x8
  _QWORD *v14; // x20
  unsigned int v15; // w22
  _QWORD *v16; // x8
  _QWORD *v17; // x8
  _QWORD *v18; // x8
  __int64 v19; // x21

  v2 = *(_QWORD **)(a1 + 48);
  v3 = *(_QWORD *)(a2 + 208);
  if ( !cser_string_defs )
  {
    result = usb_string_id(v2);
    if ( (result & 0x80000000) != 0 )
      return result;
    cser_string_defs = result;
  }
  LODWORD(result) = usb_interface_id(a1, a2);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_15;
  *(_BYTE *)(a2 + 265) = result;
  v7 = *(_BYTE *)(v3 + 193);
  byte_1F2 = result;
  byte_1F7 = v7;
  v8 = (_QWORD *)usb_ep_autoconfig(*v2, &cser_fs_in_desc);
  if ( !v8 )
    goto LABEL_14;
  *(_QWORD *)(a2 + 224) = v8;
  *v8 = v2;
  v9 = (_QWORD *)usb_ep_autoconfig(*v2, &cser_fs_out_desc);
  if ( !v9
    || (*(_QWORD *)(a2 + 232) = v9, *v9 = v2, (v10 = (_QWORD *)usb_ep_autoconfig(*v2, &cser_fs_notify_desc)) == nullptr)
    || (*(_QWORD *)(a2 + 240) = v10, *v10 = v2, v11 = usb_cser_alloc_req(), (*(_QWORD *)(a2 + 248) = v11) == 0) )
  {
LABEL_14:
    LODWORD(result) = -19;
    goto LABEL_15;
  }
  *(_QWORD *)(v11 + 48) = usb_cser_notify_complete;
  v12 = byte_1FB;
  *(_QWORD *)(*(_QWORD *)(a2 + 248) + 56LL) = a2 - 1200;
  byte_216 = v12;
  byte_21F = byte_204;
  byte_228 = v12;
  v13 = *(_QWORD *)(a1 + 48);
  byte_231 = byte_204;
  if ( *(_DWORD *)(*(_QWORD *)v13 + 76LL) >= 3u )
  {
    byte_23A = byte_20D;
    if ( *(_DWORD *)(*(_QWORD *)v13 + 76LL) >= 5u )
      byte_243 = byte_20D;
  }
  result = usb_assign_descriptors(a2, &cser_fs_function, &cser_hs_function, &cser_ss_function, &cser_ss_function);
  if ( (_DWORD)result )
  {
LABEL_15:
    v14 = *(_QWORD **)(a2 + 248);
    v15 = result;
    if ( v14 )
    {
      v19 = *(_QWORD *)(a2 + 240);
      kfree(*v14);
      usb_ep_free_request(v19, v14);
      v16 = *(_QWORD **)(a2 + 240);
      if ( !v16 )
      {
LABEL_17:
        v17 = *(_QWORD **)(a2 + 232);
        if ( !v17 )
          goto LABEL_18;
        goto LABEL_24;
      }
    }
    else
    {
      v16 = *(_QWORD **)(a2 + 240);
      if ( !v16 )
        goto LABEL_17;
    }
    *v16 = 0;
    v17 = *(_QWORD **)(a2 + 232);
    if ( !v17 )
    {
LABEL_18:
      v18 = *(_QWORD **)(a2 + 224);
      if ( !v18 )
      {
LABEL_20:
        printk(&unk_8E91, "usb_cser_bind", *(_QWORD *)a2, v15);
        return v15;
      }
LABEL_19:
      *v18 = 0;
      goto LABEL_20;
    }
LABEL_24:
    *v17 = 0;
    v18 = *(_QWORD **)(a2 + 224);
    if ( !v18 )
      goto LABEL_20;
    goto LABEL_19;
  }
  return result;
}
