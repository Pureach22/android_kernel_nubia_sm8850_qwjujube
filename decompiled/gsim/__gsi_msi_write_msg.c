__int64 __fastcall _gsi_msi_write_msg(unsigned __int64 a1, _DWORD *a2)
{
  unsigned __int64 v2; // x19
  __int64 v3; // x8
  int v4; // w12
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v7; // x8

  if ( !a1
    || a1 > 0xFFFFFFFFFFFFF000LL
    || !a2
    || (unsigned __int64)a2 > 0xFFFFFFFFFFFFF000LL
    || !gsi_ctx
    || (unsigned __int64)gsi_ctx >= 0xFFFFFFFFFFFFF001LL )
  {
    goto LABEL_15;
  }
  v2 = *(unsigned __int16 *)(a1 + 72);
  if ( *(_DWORD *)(gsi_ctx + 28680) <= (unsigned int)v2
    || ((*(_QWORD *)(gsi_ctx + ((v2 >> 3) & 0x1FF8) + 28688) >> v2) & 1) != 0 )
  {
    goto LABEL_16;
  }
  if ( (unsigned int)v2 >= 3 )
    goto LABEL_14;
  v3 = gsi_ctx + 12LL * *(unsigned __int16 *)(a1 + 72);
  v4 = a2[2];
  v5 = *(_QWORD *)(gsi_ctx + 8);
  *(_QWORD *)(v3 + 28704) = *(_QWORD *)a2;
  *(_DWORD *)(v3 + 28712) = v4;
  result = dev_notice(v5, "saved msi %u msg data %u addr 0x%08x%08x\n", v2, a2[2], a2[1], *a2);
  v7 = gsi_ctx;
  if ( (*(_BYTE *)(gsi_ctx + 28666) & 1) != 0 )
    return result;
  if ( (_DWORD)v2 == 2 )
  {
LABEL_14:
    __break(0x5512u);
LABEL_15:
    __break(0x800u);
LABEL_16:
    __break(0x800u);
    return gsi_msi_isr();
  }
  *(_QWORD *)(gsi_ctx + 28672) = *(_QWORD *)(gsi_ctx + 12LL * (unsigned int)v2 + 28704);
  *(_BYTE *)(v7 + 28666) = 1;
  return result;
}
