__int64 __fastcall adreno_ringbuffer_allocspace(__int64 a1, unsigned int a2)
{
  unsigned int rptr; // w0
  __int64 v5; // x8
  unsigned int v6; // w9
  __int64 v7; // x10
  __int64 v9; // x8

  rptr = adreno_get_rptr(a1);
  v5 = *(unsigned int *)(a1 + 16);
  v6 = v5 + a2;
  if ( rptr > (unsigned int)v5 )
    goto LABEL_2;
  if ( v6 <= 0x1FFE )
    goto LABEL_5;
  if ( rptr <= a2 )
  {
LABEL_2:
    if ( v6 < rptr )
    {
      v6 &= 0x1FFFu;
LABEL_5:
      v7 = *(_QWORD *)(a1 + 8);
      *(_DWORD *)(a1 + 16) = v6;
      return *(_QWORD *)(v7 + 8) + 4 * v5;
    }
    return -28;
  }
  else
  {
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL) + 4 * v5) = (0x1FFF - v5)
                                                                 | 0x70100000
                                                                 | (0x4B348000u >> ((((unsigned int)(0x1FFF - v5) >> 4)
                                                                                   ^ ((unsigned __int16)(0x1FFF - v5) >> 8)
                                                                                   ^ ((unsigned int)(0x1FFF - v5) >> 12)
                                                                                   ^ ((unsigned int)(0x1FFF - v5) >> 16)
                                                                                   ^ ((unsigned int)(0x1FFF - v5) >> 20)
                                                                                   ^ ((unsigned int)(0x1FFF - v5) >> 24)
                                                                                   ^ ((unsigned int)(0x1FFF - v5) >> 28)
                                                                                   ^ (-1 - v5))
                                                                                  & 0xF))
                                                                 & 0x8000;
    v9 = *(_QWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 16) = a2;
    return *(_QWORD *)(v9 + 8);
  }
}
