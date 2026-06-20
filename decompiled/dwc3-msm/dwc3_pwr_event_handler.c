__int64 __fastcall dwc3_pwr_event_handler(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  __int16 v4; // w21
  __int64 v5; // x8
  bool v6; // zf
  __int64 v7; // x8
  int v8; // w8
  unsigned int v9; // w0
  __int64 v10; // x8
  unsigned int v11; // w20
  int v12; // w8

  v1 = *(_QWORD *)(result + 40);
  if ( v1 )
  {
    v2 = result;
    if ( *(_BYTE *)(result + 756) == 1 )
    {
      v3 = *(_QWORD *)(v1 + 168);
      v4 = readl((unsigned int *)(*(_QWORD *)(result + 8) + 1017944LL));
      if ( (~(_BYTE)v4 & 0xC) != 0 )
      {
        if ( (v4 & 8) != 0 )
        {
          *(_DWORD *)(v2 + 828) = 0;
          v9 = 8;
          if ( (v4 & 0x2000) == 0 )
            return writel(v9, (unsigned int *)(*(_QWORD *)(v2 + 8) + 1017944LL));
        }
        else if ( (v4 & 4) != 0 )
        {
          v9 = 4;
          *(_DWORD *)(v2 + 828) = 1;
          if ( (v4 & 0x2000) == 0 )
            return writel(v9, (unsigned int *)(*(_QWORD *)(v2 + 8) + 1017944LL));
        }
        else
        {
          v9 = 0;
          if ( (v4 & 0x2000) == 0 )
            return writel(v9, (unsigned int *)(*(_QWORD *)(v2 + 8) + 1017944LL));
        }
      }
      else
      {
        v5 = *(_QWORD *)(v2 + 40);
        if ( v5 )
        {
          v6 = *(_DWORD *)(*(_QWORD *)(v5 + 168) + 1248LL) == 21811;
          v7 = 53328;
          if ( v6 )
            v7 = 49508;
          v8 = readl((unsigned int *)(*(_QWORD *)(v2 + 8) + v7));
          v9 = 12;
          *(_DWORD *)(v2 + 828) = (v8 & 0x3C00000) == 12582912;
          if ( (v4 & 0x2000) == 0 )
            return writel(v9, (unsigned int *)(*(_QWORD *)(v2 + 8) + 1017944LL));
          goto LABEL_18;
        }
        v9 = 12;
        if ( (v4 & 0x2000) == 0 )
          return writel(v9, (unsigned int *)(*(_QWORD *)(v2 + 8) + 1017944LL));
      }
LABEL_18:
      if ( (*(_BYTE *)(v2 + 736) & 1) == 0 )
      {
        v10 = *(_QWORD *)(v3 + 848);
        v11 = v9;
        v12 = usb_gadget_wakeup(v10);
        v9 = v11;
        if ( v12 )
        {
          dev_err(*(_QWORD *)v2, "%s failed to take dwc out of L1\n", "dwc3_pwr_event_handler");
          v9 = v11;
        }
      }
      v9 |= 0x2000u;
      return writel(v9, (unsigned int *)(*(_QWORD *)(v2 + 8) + 1017944LL));
    }
  }
  return result;
}
