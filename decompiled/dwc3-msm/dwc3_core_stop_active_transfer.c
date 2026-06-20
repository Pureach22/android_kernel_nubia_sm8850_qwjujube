__int64 __fastcall dwc3_core_stop_active_transfer(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x19
  _QWORD *v3; // x22
  _QWORD *v4; // x20
  _QWORD *v5; // x8
  char v6; // w23
  int v7; // w0
  int v8; // w8
  int v9; // w8
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  int v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(unsigned __int8 *)(result + 170) >= 0x20uLL )
    goto LABEL_19;
  v1 = *(_QWORD *)(result + 152);
  v2 = result;
  v3 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(v1 + 368) + 96LL) + 152LL);
  v4 = v3 + 159;
  if ( (v3[5 * *(unsigned __int8 *)(result + 170) + 163] & 1) != 0 && (*(_BYTE *)(result + 165) & 0x20) == 0 )
  {
    v5 = &v4[5 * *(unsigned __int8 *)(result + 170)];
    if ( *((_DWORD *)v5 + 2) == 1 )
    {
      v6 = *((_BYTE *)v5 + 24);
      v7 = readl(v3[1] + (unsigned int)(*(_DWORD *)(v3[62] + 96LL) + 1015808));
      writel(v7 | (unsigned int)(1 << v6), v3[1] + (unsigned int)(*(_DWORD *)(v3[62] + 96LL) + 1015808));
    }
    v8 = *(unsigned __int8 *)(v2 + 172);
    v10 = 0;
    v11 = 0;
    result = dwc3_core_send_gadget_ep_cmd(v2, (v8 << 16) | 0x808u, &v10);
    if ( (_DWORD)result && (__break(0x800u), (_DWORD)result == -110) && *(_DWORD *)(*(_QWORD *)(v2 + 152) + 1264LL) != 1 )
    {
      *(_DWORD *)(v2 + 164) |= 0x2008u;
      result = dwc3_dbg_print(v3[157], 0xFFu, "core ENDXFER", -110, (const char *)&unk_16A05);
    }
    else
    {
      *(_BYTE *)(v2 + 172) = 0;
      v9 = *(_DWORD *)(v1 + 1248);
      if ( v9 == 13105 || v9 == 21811 && *(_DWORD *)(v1 + 1252) <= 0x55333109u )
        result = _const_udelay(429500);
      if ( (*(_BYTE *)(v2 + 204) & 2) != 0 )
        *(_DWORD *)(v2 + 164) |= 0x100u;
    }
    if ( *(unsigned __int8 *)(v2 + 170) <= 0x1FuLL )
    {
      v4[5 * *(unsigned __int8 *)(v2 + 170) + 4] &= ~1uLL;
      goto LABEL_15;
    }
LABEL_19:
    __break(0x5512u);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
