__int64 __fastcall rmnet_wlan_udp_encap_check(__int64 result, unsigned __int16 *a2, unsigned int a3)
{
  int v3; // w8
  char *v4; // x9
  int v5; // w8
  int v6; // w9
  __int16 *v7; // x9
  __int64 v8; // x1
  int *v9; // x19
  unsigned int v10; // w19
  int v11; // w8
  __int64 v12; // [xsp+0h] [xbp-20h]
  int v13; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *((_BYTE *)a2 + 5) != 17 )
    goto LABEL_16;
  v3 = *a2;
  v14[0] = 0;
  v4 = (char *)&rmnet_wlan_encap_hash + 8 * ((unsigned int)(1640531527 * v3) >> 28);
  do
  {
    v4 = *(char **)v4;
    if ( !v4 )
      goto LABEL_16;
  }
  while ( *((unsigned __int16 *)v4 + 16) != v3 );
  v6 = *(_DWORD *)(result + 112);
  v5 = *(_DWORD *)(result + 116);
  v13 = 0;
  if ( (int)(v6 - (v5 + a3)) > 7 )
  {
    v7 = (__int16 *)(*(_QWORD *)(result + 224) + (int)a3);
    if ( !v7 )
      goto LABEL_16;
    goto LABEL_7;
  }
  if ( !result )
    goto LABEL_17;
  v10 = a3;
  v12 = result;
  v11 = skb_copy_bits(result, a3, v14, 8);
  result = v12;
  v7 = (__int16 *)v14;
  a3 = v10;
  if ( v11 < 0 )
  {
LABEL_16:
    result = 0;
    goto LABEL_17;
  }
LABEL_7:
  if ( *v7 == -3071 )
    goto LABEL_16;
  v8 = a3 + 8;
  if ( (int)(*(_DWORD *)(result + 112) - (*(_DWORD *)(result + 116) + a3) - 8) > 3 )
  {
    v9 = (int *)(*(_QWORD *)(result + 224) + (int)v8);
    if ( !v9 )
      goto LABEL_16;
    goto LABEL_10;
  }
  if ( result )
  {
    v9 = &v13;
    if ( (skb_copy_bits(result, v8, &v13, 4) & 0x80000000) == 0 )
    {
LABEL_10:
      result = *v9 != 0;
      goto LABEL_17;
    }
    goto LABEL_16;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
