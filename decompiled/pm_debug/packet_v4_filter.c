__int64 __fastcall packet_v4_filter(__int64 result, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w8
  unsigned __int8 *v4; // x20
  int v5; // w8
  unsigned __int8 v6; // w10
  unsigned int v7; // w9
  __int64 v8; // x8
  int v9; // w8
  int v10; // w8
  __int64 v11; // x19
  unsigned int v12; // w20
  __int64 v13; // x20
  unsigned int v14; // w19
  __int64 v15; // x19
  unsigned int v16; // w20
  unsigned int v17; // w21
  __int64 v18; // x22
  __int64 v19; // x19
  int v20; // w0
  int v21; // w8
  _QWORD v22[2]; // [xsp+30h] [xbp-20h] BYREF
  int v23; // [xsp+40h] [xbp-10h]
  __int64 v24; // [xsp+48h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_10;
  v23 = 0;
  v22[0] = 0;
  v22[1] = 0;
  if ( (tcp_output_debug & 1) == 0 )
    goto LABEL_10;
  if ( *(_WORD *)(result + 180) != 8 )
    goto LABEL_10;
  v3 = *(_DWORD *)(result + 112);
  if ( v3 < 0x14 )
    goto LABEL_10;
  if ( (int)(v3 - *(_DWORD *)(result + 116)) <= 19 )
  {
    v17 = a3;
    v18 = a2;
    v19 = result;
    v4 = (unsigned __int8 *)v22;
    v20 = skb_copy_bits();
    a2 = v18;
    a3 = v17;
    v21 = v20;
    result = v19;
    if ( v21 < 0 )
      goto LABEL_10;
  }
  else
  {
    v4 = *(unsigned __int8 **)(result + 224);
    if ( !v4 )
      goto LABEL_10;
  }
  v5 = *v4;
  if ( (v5 & 0xFu) < 5 )
    goto LABEL_10;
  if ( (v5 & 0xF0) != 0x40 )
    goto LABEL_10;
  v6 = 4 * v5;
  v7 = *(_DWORD *)(result + 112);
  if ( v7 < ((4 * v5) & 0xFCu) )
    goto LABEL_10;
  v8 = 16;
  if ( a3 )
    v8 = 12;
  v9 = *(_DWORD *)&v4[v8];
  if ( !v9 || (unsigned __int8)v9 == 127 )
    goto LABEL_10;
  v10 = v4[9];
  switch ( v10 )
  {
    case 1:
      if ( v7 < v6 )
        goto LABEL_10;
      if ( v7 < (unsigned __int8)(v6 + 8) )
        goto LABEL_10;
      v13 = a2;
      v14 = a3;
      result = skb_header_pointer();
      if ( !result )
        goto LABEL_10;
      get_uid_from_state(v13);
      if ( v14 > 1 )
        break;
      result = printk(&unk_98D1);
LABEL_10:
      _ReadStatusReg(SP_EL0);
      return result;
    case 17:
      if ( v7 < v6 )
        goto LABEL_10;
      if ( v7 < (unsigned __int8)(v6 + 8) )
        goto LABEL_10;
      v15 = a2;
      v16 = a3;
      result = skb_header_pointer();
      if ( !result )
        goto LABEL_10;
      get_uid_from_state(v15);
      result = can_print_packet();
      if ( (result & 1) == 0 )
        goto LABEL_10;
      if ( v16 <= 1 )
      {
LABEL_34:
        result = printk(&unk_989A);
        goto LABEL_10;
      }
      break;
    case 6:
      if ( v7 < v6 )
        goto LABEL_10;
      if ( v7 < (unsigned __int8)(v6 + 20) )
        goto LABEL_10;
      v11 = a2;
      v12 = a3;
      result = skb_header_pointer();
      if ( !result )
        goto LABEL_10;
      get_uid_from_state(v11);
      result = can_print_packet();
      if ( (result & 1) == 0 )
        goto LABEL_10;
      if ( v12 <= 1 )
        goto LABEL_34;
      break;
    default:
      if ( a3 <= 1 )
      {
        result = printk(&unk_9B08);
        goto LABEL_10;
      }
      break;
  }
  __break(1u);
  return skb_header_pointer();
}
