__int64 __fastcall qdss_eps_disable(__int64 a1)
{
  __int64 result; // x0
  char v3; // w8
  char v4; // w8

  result = ipc_log_string(qdss_ipc_log, "%s: channel:%s\n", "qdss_eps_disable", *(const char **)(a1 + 296));
  v3 = *(_BYTE *)(a1 + 460);
  if ( (v3 & 2) != 0 )
  {
    result = usb_ep_disable(*(_QWORD *)(a1 + 232));
    v3 = *(_BYTE *)(a1 + 460) & 0xFD;
    *(_BYTE *)(a1 + 460) = v3;
    if ( (v3 & 4) == 0 )
    {
LABEL_3:
      if ( (v3 & 1) == 0 )
        return result;
      goto LABEL_4;
    }
  }
  else if ( (*(_BYTE *)(a1 + 460) & 4) == 0 )
  {
    goto LABEL_3;
  }
  result = usb_ep_disable(*(_QWORD *)(a1 + 224));
  v4 = *(_BYTE *)(a1 + 460) & 0xFB;
  *(_BYTE *)(a1 + 460) = v4;
  if ( (v4 & 1) == 0 )
    return result;
LABEL_4:
  result = usb_ep_disable(*(_QWORD *)(a1 + 240));
  *(_BYTE *)(a1 + 460) &= ~1u;
  return result;
}
