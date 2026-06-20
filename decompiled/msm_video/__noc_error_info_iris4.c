__int64 __fastcall _noc_error_info_iris4(__int64 a1)
{
  int v2; // w0
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  v2 = _read_register(a1, 0xB0080u, (_DWORD *)v4 + 1);
  if ( !(v2 | BYTE4(v4[0]) & 2) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8E0DA, "err ", 0xFFFFFFFFLL, "codec", "__noc_error_info_iris4");
LABEL_28:
    result = 0;
    goto LABEL_29;
  }
  if ( !(unsigned int)_read_register(a1, 0x1A020u, v4) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_87F5C, "err ", 0xFFFFFFFFLL, "codec", "__noc_error_info_iris4");
  if ( !(unsigned int)_read_register(a1, 0x1A024u, v4) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_81E53, "err ", 0xFFFFFFFFLL, "codec", "__noc_error_info_iris4");
  if ( !(unsigned int)_read_register(a1, 0x1A028u, v4) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_92BA4, "err ", 0xFFFFFFFFLL, "codec", "__noc_error_info_iris4");
  if ( !(unsigned int)_read_register(a1, 0x1A02Cu, v4) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_7F690, "err ", 0xFFFFFFFFLL, "codec", "__noc_error_info_iris4");
  if ( !(unsigned int)_read_register(a1, 0x1A030u, v4) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_8FAC5, "err ", 0xFFFFFFFFLL, "codec", "__noc_error_info_iris4");
  if ( !(unsigned int)_read_register(a1, 0x1A034u, v4) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_863D9, "err ", 0xFFFFFFFFLL, "codec", "__noc_error_info_iris4");
  if ( !(unsigned int)_read_register(a1, 0x1A038u, v4) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_91FFD, "err ", 0xFFFFFFFFLL, "codec", "__noc_error_info_iris4");
  result = _read_register(a1, 0x1A03Cu, v4);
  if ( !(_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_832B9, "err ", 0xFFFFFFFFLL, "codec", "__noc_error_info_iris4");
    goto LABEL_28;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
