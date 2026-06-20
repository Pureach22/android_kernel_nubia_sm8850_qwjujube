__int64 __fastcall rmnet_frag_ingress_handler(__int64 result, __int64 a2)
{
  int v3; // w11
  unsigned __int64 v4; // x26
  __int64 v5; // x21
  __int64 *v6; // x8
  __int64 v7; // x20
  _QWORD *v8; // x9
  __int64 v9; // x8
  _QWORD *v10; // x28
  int v11; // w8
  __int64 v12; // x22
  _QWORD *v13; // x8
  _QWORD *v14; // t2
  int v15; // w20
  char *v16; // x0
  int v17; // w9
  _BYTE *v18; // x24
  unsigned __int16 v19; // w23
  int v20; // w1
  unsigned __int8 *endpoint; // x0
  __int64 *v22; // x1
  _QWORD *v23; // x1
  _QWORD *v24; // x0
  int v25; // w8
  _QWORD *v26; // x9
  _QWORD *v27; // x8
  _QWORD *v28; // x20
  _QWORD *v29; // x8
  int v30; // [xsp+Ch] [xbp-54h]
  __int64 v31; // [xsp+10h] [xbp-50h]
  _QWORD *v32; // [xsp+18h] [xbp-48h]
  _QWORD *v33; // [xsp+20h] [xbp-40h]
  __int64 v34; // [xsp+28h] [xbp-38h]
  _QWORD v35[2]; // [xsp+30h] [xbp-30h] BYREF
  _QWORD *v36; // [xsp+40h] [xbp-20h] BYREF
  __int64 *v37; // [xsp+48h] [xbp-18h]
  int v38; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+58h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(result + 144);
  v35[0] = v35;
  v35[1] = v35;
  if ( !result )
  {
    v4 = 0;
    v29 = (_QWORD *)(a2 + 2608);
    goto LABEL_57;
  }
  v4 = 0;
  v31 = a2 + 2672;
  v32 = (_QWORD *)(a2 + 2704);
  v5 = result;
  v30 = v3;
  v33 = (_QWORD *)(a2 + 2664);
  v34 = result;
  while ( 2 )
  {
    v8 = v33;
    v9 = *(unsigned __int8 *)(*(_QWORD *)(v5 + 216) + *(unsigned int *)(v5 + 212) + 2LL);
    if ( (unsigned int)v9 >= 2 )
    {
      v8 = v32;
      if ( (unsigned int)v9 <= 0xF )
        v8 = (_QWORD *)(v31 + ((2 * (int)v9) & 0x1F8LL));
    }
    *v8 += v9;
    ((void (__fastcall *)(__int64, __int64, _QWORD *, _QWORD))rmnet_frag_deaggregate)(
      v5,
      a2,
      v35,
      *(unsigned int *)(v5 + 144));
    v10 = (_QWORD *)v35[0];
    while ( v10 != v35 )
    {
      v12 = (__int64)v10;
      v14 = v10;
      v10 = (_QWORD *)*v10;
      v13 = (_QWORD *)v14[1];
      if ( *v13 == v12 && v10[1] == v12 )
      {
        v10[1] = v13;
        *v13 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v12);
      }
      *(_QWORD *)v12 = v12;
      *(_QWORD *)(v12 + 8) = v12;
      v15 = *(_DWORD *)(v12 + 56);
      v38 = 0;
      v36 = &v36;
      v37 = (__int64 *)&v36;
      v16 = (char *)rmnet_frag_header_ptr(v12, 0, 4u, (__int64)&v38);
      if ( !v16 )
        goto LABEL_12;
      v17 = *v16;
      v18 = v16;
      v19 = (bswap32(*((unsigned __int16 *)v16 + 1)) >> 16) - (v17 & 0x3F);
      if ( v17 < 0 )
      {
        qmi_rmnet_set_dl_msg_active(a2);
        v11 = *(_DWORD *)(a2 + 8);
        if ( (v11 & 0x60000000) != 0 )
        {
          rmnet_frag_flow_command(v12, a2, v19);
        }
        else if ( (v11 & 2) != 0 )
        {
          rmnet_frag_command(v12, (__int64)v18, (_QWORD *)a2);
        }
        goto LABEL_12;
      }
      v20 = (unsigned __int8)v16[1];
      if ( v20 == 255 )
        goto LABEL_12;
      endpoint = rmnet_get_endpoint(a2, v20);
      if ( !endpoint )
        goto LABEL_12;
      *(_QWORD *)(v12 + 32) = *((_QWORD *)endpoint + 1);
      if ( (*v18 & 0x40) != 0 && (*(_BYTE *)(a2 + 8) & 0x30) != 0 )
      {
        if ( !(unsigned int)rmnet_frag_process_next_hdr_packet(v12, a2, &v36, v19) )
          goto LABEL_31;
LABEL_12:
        rmnet_recycle_frag_descriptor((_QWORD *)v12, a2);
      }
      else if ( rmnet_frag_pull(v12, a2, 4u) && rmnet_frag_trim(v12, a2, v19) )
      {
        v22 = v37;
        if ( &v36 != (_QWORD **)v12 && v37 != (__int64 *)v12 && (_QWORD **)*v37 == &v36 )
        {
          v37 = (__int64 *)v12;
          *(_QWORD *)v12 = &v36;
          *(_QWORD *)(v12 + 8) = v22;
          *v22 = v12;
LABEL_31:
          if ( (*(_BYTE *)(a2 + 11) & 8) != 0 )
            goto LABEL_32;
          goto LABEL_36;
        }
        _list_add_valid_or_report(v12, v37, &v36);
        if ( (*(_BYTE *)(a2 + 11) & 8) != 0 )
        {
LABEL_32:
          if ( v36 == &v36 )
            v23 = nullptr;
          else
            v23 = v36;
          qmi_rmnet_work_maybe_restart(a2, v23, 0);
        }
LABEL_36:
        if ( v15 == 55834 )
        {
          v24 = v36;
          if ( v36 != &v36 )
          {
            do
            {
LABEL_46:
              v28 = (_QWORD *)*v24;
              v27 = (_QWORD *)v24[1];
              if ( (_QWORD *)*v27 == v24 && (_QWORD *)v28[1] == v24 )
              {
                v28[1] = v27;
                *v27 = v28;
              }
              else
              {
                _list_del_entry_valid_or_report(v24);
                v24 = v26;
              }
              *v24 = v24;
              v24[1] = v24;
              rmnet_frag_deliver((__int64)v24, a2);
              v24 = v28;
            }
            while ( v28 != &v36 );
          }
        }
        else
        {
          v25 = rmnet_module_hook_offload_ingress(&v36, a2);
          v24 = v36;
          if ( !v25 && v36 != &v36 )
            goto LABEL_46;
        }
      }
    }
    v6 = (__int64 *)v5;
    if ( v5 == v34 )
      v6 = (__int64 *)(*(_QWORD *)(v5 + 216) + *(unsigned int *)(v5 + 212) + 8LL);
    v7 = *v6;
    ++v4;
    *v6 = 0;
    result = consume_skb(v5);
    v5 = v7;
    if ( v7 )
      continue;
    break;
  }
  v3 = v30;
  v29 = (_QWORD *)(a2 + 8LL * ((unsigned __int8)v4 / 0xAu) + 2608);
  if ( v4 > 0x3B )
    v29 = (_QWORD *)(a2 + 2656);
LABEL_57:
  *v29 += v4;
  if ( v3 != 55834 )
    result = rmnet_module_hook_offload_chain_end(result);
  _ReadStatusReg(SP_EL0);
  return result;
}
