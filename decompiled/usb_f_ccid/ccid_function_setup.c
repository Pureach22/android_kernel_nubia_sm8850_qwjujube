__int64 __fastcall ccid_function_setup(__int64 a1, unsigned __int16 *a2)
{
  unsigned __int16 v3; // w10
  _QWORD *v4; // x19
  unsigned int v5; // w9
  __int64 v6; // x1
  unsigned int v7; // w8
  __int64 result; // x0
  int *v9; // x8
  int v10; // w8
  __int64 v11; // x2
  __int64 v12; // x20
  unsigned int v13; // w19

  v3 = a2[1];
  v4 = *(_QWORD **)(*(_QWORD *)(a1 + 48) + 48LL);
  v5 = a2[3];
  v6 = v4[1];
  if ( !*(_DWORD *)(a1 + 232) )
    return 4294967189LL;
  v7 = __rev16(*a2);
  if ( v7 == 41219 )
  {
    v9 = &dword_27B;
  }
  else
  {
    if ( v7 != 41218 )
    {
      if ( v7 != 8449 || v5 )
        return 4294967201LL;
      *(_BYTE *)(a1 + 321) = v3;
      *(_BYTE *)(a1 + 320) = 1;
      v12 = v6;
      *(_BYTE *)(a1 + 322) = HIBYTE(v3);
      *(_BYTE *)(a1 + 323) = 0;
      *(_DWORD *)(a1 + 324) = 1;
      _wake_up(a1 + 296, 3, 1, 0);
      v6 = v12;
      v10 = 0;
      goto LABEL_13;
    }
    v9 = &dword_272;
  }
  **(_DWORD **)v6 = *v9;
  if ( v5 >= 4 )
    v10 = 4;
  else
    v10 = v5;
LABEL_13:
  *(_DWORD *)(v6 + 8) = v10;
  result = usb_ep_queue(*(_QWORD *)(*v4 + 48LL), v6, 2080);
  if ( (result & 0x80000000) != 0 )
  {
    v13 = result;
    printk(&unk_8284, (unsigned int)result, v11);
    return v13;
  }
  return result;
}
