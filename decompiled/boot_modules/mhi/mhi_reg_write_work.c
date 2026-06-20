__int64 __fastcall mhi_reg_write_work(__int64 result)
{
  __int64 v1; // x23
  _BYTE *v2; // x22
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v5; // x20

  v1 = *(_QWORD *)(result + 32) + 16LL * *(unsigned int *)(result + 44);
  v2 = (_BYTE *)(v1 + 12);
  if ( *(_BYTE *)(v1 + 12) == 1 )
  {
    v3 = *(_QWORD *)(result - 104);
    v4 = result;
    if ( (unsigned int)(*(_DWORD *)(v3 + 348) - 2) <= 4 )
    {
      v5 = *(_QWORD *)(v3 + 8) - 200LL;
      result = msm_pcie_prevent_l1(v5);
      if ( !(_DWORD)result )
      {
        if ( *v2 == 1 )
        {
          do
          {
            if ( (unsigned int)(*(_DWORD *)(v3 + 348) - 2) > 4 )
              break;
            __dmb(9u);
            writel_relaxed(*(unsigned int *)(v1 + 8), *(_QWORD *)v1);
            *v2 = 0;
            v1 = *(_QWORD *)(v4 + 32) + 16LL * (((unsigned __int16)*(_DWORD *)(v4 + 44) + 1) & 0x1FF);
            *(_DWORD *)(v4 + 44) = ((unsigned __int16)*(_DWORD *)(v4 + 44) + 1) & 0x1FF;
            v2 = (_BYTE *)(v1 + 12);
          }
          while ( (*(_BYTE *)(v1 + 12) & 1) != 0 );
        }
        return msm_pcie_allow_l1(v5);
      }
    }
  }
  return result;
}
