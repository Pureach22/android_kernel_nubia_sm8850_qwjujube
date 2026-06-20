__int64 __fastcall usb_cser_setup(__int64 a1, unsigned __int16 *a2)
{
  _QWORD *v2; // x21
  unsigned int v3; // w10
  unsigned int v4; // w9
  __int64 v5; // x19
  __int64 v6; // x22
  size_t v7; // x20
  __int64 result; // x0
  void (__fastcall *v9)(_QWORD); // x9
  __int64 v10; // x0
  int v11; // w8
  unsigned int v12; // w19

  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 48) + 48LL);
  v3 = __rev16(*a2);
  v4 = a2[3];
  v5 = v2[1];
  if ( v3 == 41249 )
  {
    if ( v4 >= 7 )
      v7 = 7;
    else
      v7 = a2[3];
    v6 = a1;
    memcpy(*(void **)v5, (const void *)(a1 + 256), v7);
  }
  else if ( v3 == 8482 )
  {
    v9 = *(void (__fastcall **)(_QWORD))(a1 + 336);
    v6 = a1;
    *(_WORD *)(a1 + 268) = a2[1];
    if ( v9 )
    {
      v10 = a1 - 1200;
      if ( *((_DWORD *)v9 - 1) != 1607364836 )
        __break(0x8229u);
      v9(v10);
    }
    LODWORD(v7) = 0;
  }
  else
  {
    if ( v3 != 8480 || v4 != 7 )
      return 4294967201LL;
    v6 = a1;
    LODWORD(v7) = 7;
    **(_QWORD **)(*v2 + 48LL) = a1 - 1200;
    *(_QWORD *)(v5 + 48) = port_complete_set_line_coding;
  }
  v11 = *(_DWORD *)(v5 + 40);
  *(_DWORD *)(v5 + 8) = v7;
  *(_DWORD *)(v5 + 40) = v11 & 0xFFFBFFFF;
  result = usb_ep_queue(*(_QWORD *)(*v2 + 48LL), v5, 2080);
  if ( (result & 0x80000000) != 0 )
  {
    v12 = result;
    printk(&unk_9044, "usb_cser_setup", v6 - 148, (unsigned int)result);
    return v12;
  }
  return result;
}
