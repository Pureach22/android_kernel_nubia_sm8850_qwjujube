__int64 msm_pinctrl_hibernation_resume()
{
  unsigned __int64 v0; // x27
  __int64 v1; // x21
  __int64 v2; // x22
  __int64 v3; // x23
  unsigned __int64 v4; // x24
  __int64 v5; // x25
  _QWORD *v6; // x8
  unsigned int *v7; // x20
  __int64 result; // x0
  __int64 v9; // x20
  unsigned __int64 v10; // x19
  __int64 v11; // x23
  __int64 v12; // x24
  unsigned int *v13; // x25
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x23
  __int64 v17; // x20
  __int64 v18; // x24
  __int64 v19; // x25
  __int64 v20; // x26
  __int64 v21; // x8
  __int64 v22; // x8

  v1 = msm_pinctrl_data;
  if ( *(_BYTE *)(msm_pinctrl_data + 1040) == 1
    && *(_QWORD *)(msm_pinctrl_data + 1024)
    && *(_QWORD *)(msm_pinctrl_data + 1032) )
  {
    v2 = *(_QWORD *)(msm_pinctrl_data + 968);
    if ( *(_DWORD *)(v2 + 64) )
    {
      v3 = 0;
      v4 = 0;
      v5 = msm_pinctrl_data + 976;
      do
      {
        v6 = (_QWORD *)(v1 + 976);
        if ( *(_QWORD *)(v2 + 56) )
        {
          if ( v4 >= 4 )
          {
            __break(0x5512u);
            _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
            return pinctrl_hibernation_notifier();
          }
          v6 = (_QWORD *)(v5 + v3);
        }
        v7 = (unsigned int *)(*v6 + *(unsigned int *)(*(_QWORD *)(v2 + 120) + 4 * v4));
        printk(&unk_D405, v7);
        writel_relaxed(*(_DWORD *)(*(_QWORD *)(v1 + 1032) + 4 * v3), v7);
        writel_relaxed(*(_DWORD *)(*(_QWORD *)(v1 + 1032) + 4 * v3 + 4), v7 + 1);
        writel_relaxed(*(_DWORD *)(*(_QWORD *)(v1 + 1032) + 4 * v3 + 8), v7 + 2);
        writel_relaxed(*(_DWORD *)(*(_QWORD *)(v1 + 1032) + 4 * v3 + 12), v7 + 3);
        writel_relaxed(*(_DWORD *)(*(_QWORD *)(v1 + 1032) + 4 * v3 + 16), v7 + 4);
        writel_relaxed(*(_DWORD *)(*(_QWORD *)(v1 + 1032) + 4 * v3 + 20), v7 + 5);
        writel_relaxed(*(_DWORD *)(*(_QWORD *)(v1 + 1032) + 4 * v3 + 24), v7 + 6);
        result = writel_relaxed(*(_DWORD *)(*(_QWORD *)(v1 + 1032) + 4 * v3 + 28), v7 + 7);
        ++v4;
        v3 += 8;
      }
      while ( v4 < *(unsigned int *)(v2 + 64) );
    }
    if ( *(_DWORD *)(v2 + 44) )
    {
      v9 = 0;
      v10 = 0;
      v11 = v1 + 976;
      v12 = 60;
      do
      {
        v13 = (unsigned int *)(*(_QWORD *)(v2 + 32) + v12);
        writel(
          *(_DWORD *)(*(_QWORD *)(v1 + 1024) + v9),
          (unsigned int *)(*(_QWORD *)(v11 + 8 * ((*((_QWORD *)v13 + 3) >> 5) & 3LL)) + *v13));
        result = writel(
                   *(_DWORD *)(*(_QWORD *)(v1 + 1024) + v9 + 4),
                   (unsigned int *)(*(_QWORD *)(v11 + 8 * ((*((_QWORD *)v13 + 3) >> 5) & 3LL)) + v13[1]));
        v14 = v13[2];
        if ( (_DWORD)v14 )
          result = writel(
                     *(_DWORD *)(*(_QWORD *)(v1 + 1024) + v9 + 8),
                     (unsigned int *)(*(_QWORD *)(v11 + 8 * ((*((_QWORD *)v13 + 3) >> 5) & 3LL)) + v14));
        v15 = v13[3];
        if ( (_DWORD)v15 )
          result = writel(
                     *(_DWORD *)(*(_QWORD *)(v1 + 1024) + v9 + 12),
                     (unsigned int *)(*(_QWORD *)(v11 + 8 * ((*((_QWORD *)v13 + 3) >> 5) & 3LL)) + v15));
        ++v10;
        v9 += 16;
        v12 += 112;
      }
      while ( v10 < *(unsigned int *)(v2 + 44) );
    }
    else
    {
      LODWORD(v10) = 0;
    }
    if ( (unsigned int)v10 < *(_DWORD *)(v2 + 40) )
    {
      v16 = v1 + 976;
      v10 = (unsigned int)v10;
      v17 = 16LL * (unsigned int)v10;
      v18 = 112LL * (unsigned int)v10;
      do
      {
        v19 = *(_QWORD *)(v2 + 32);
        v20 = v19 + v18;
        v21 = *(unsigned int *)(v19 + v18 + 60);
        if ( (_DWORD)v21 )
          result = writel(
                     *(_DWORD *)(*(_QWORD *)(v1 + 1024) + v17),
                     (unsigned int *)(*(_QWORD *)(v16 + 8 * ((*(_QWORD *)(v20 + 84) >> 5) & 3LL)) + v21));
        v22 = *(unsigned int *)(v20 + 64);
        if ( (_DWORD)v22 )
          result = writel(
                     *(_DWORD *)(*(_QWORD *)(v1 + 1024) + v17 + 4),
                     (unsigned int *)(*(_QWORD *)(v16 + 8 * ((*(_QWORD *)(v19 + v18 + 84) >> 5) & 3LL)) + v22));
        ++v10;
        v18 += 112;
        v17 += 16;
      }
      while ( v10 < *(unsigned int *)(v2 + 40) );
    }
  }
  return result;
}
