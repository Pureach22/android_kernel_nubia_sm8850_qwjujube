__int64 __fastcall hdcp2_app_comm(__int64 a1, int a2, __int64 a3)
{
  unsigned int v5; // w22
  unsigned int v7; // w21
  _DWORD *v8; // x8
  __int64 (__fastcall *v9)(__int64); // x8
  __int64 (__fastcall *v10)(__int64, __int64); // x8

  if ( !a1 || !a3 )
  {
    printk(&unk_CF99);
    return (unsigned int)-22;
  }
  v5 = *(_DWORD *)(a3 + 16);
  mutex_lock(&hdcp2_mutex_g);
  v7 = 0;
  if ( a2 <= 2 )
  {
    if ( a2 )
    {
      if ( a2 != 1 )
      {
        if ( a2 != 2 )
          goto LABEL_27;
        v9 = (__int64 (__fastcall *)(__int64))off_BCC0;
        if ( *((_DWORD *)off_BCC0 - 1) != -1066802076 )
          __break(0x8228u);
        v7 = v9(a1);
        if ( v7 )
          goto LABEL_27;
LABEL_24:
        v10 = (__int64 (__fastcall *)(__int64, __int64))off_BCE8;
        if ( *((_DWORD *)off_BCE8 - 1) != 2007774812 )
          __break(0x8228u);
        v7 = v10(a1, a3);
        goto LABEL_27;
      }
      v8 = (_DWORD *)qword_BC98;
    }
    else
    {
      v8 = (_DWORD *)qword_BC90;
    }
LABEL_21:
    if ( *(v8 - 1) != 19073560 )
      __break(0x8228u);
    v7 = ((__int64 (__fastcall *)(__int64, _QWORD))v8)(a1, v5);
    if ( v7 )
      goto LABEL_27;
    goto LABEL_24;
  }
  if ( a2 <= 4 )
  {
    if ( a2 == 3 )
      v8 = (_DWORD *)qword_BCA0;
    else
      v8 = off_BCA8;
    goto LABEL_21;
  }
  if ( a2 == 5 )
  {
    v8 = (_DWORD *)qword_BCB0;
    goto LABEL_21;
  }
  if ( a2 == 6 )
  {
    v8 = (_DWORD *)qword_BCB8;
    goto LABEL_21;
  }
LABEL_27:
  mutex_unlock(&hdcp2_mutex_g);
  return v7;
}
