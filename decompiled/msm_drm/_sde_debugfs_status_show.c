__int64 __fastcall sde_debugfs_status_show(__int64 a1)
{
  __int64 *v1; // x19
  __int64 v3; // x27
  int v4; // w21
  int v5; // w22
  unsigned __int64 v6; // x23
  __int64 *v7; // x28
  __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // x0
  unsigned __int64 v11; // x21
  unsigned __int16 *v12; // x25
  __int64 v13; // x8
  __int64 *v14; // x21
  __int64 v15; // x22
  __int64 v16; // x23
  __int64 v17; // x0
  int v18; // w3
  __int64 v19; // x4
  __int64 v20; // x2
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v1 = *(__int64 **)(a1 + 128)) != nullptr )
  {
    v3 = v1[251];
    v21[0] = 0;
    mutex_lock(v1 + 577);
    sde_crtc_get_mixer_resolution(v1, v1[251], v1[251] + 24, (_DWORD *)v21 + 1, v21);
    v5 = v21[0];
    v4 = HIDWORD(v21[0]);
    seq_printf(
      a1,
      "crtc:%d width:%d height:%d\n",
      *((_DWORD *)v1 + 28),
      *((_DWORD *)v1 + 548) * HIDWORD(v21[0]),
      LODWORD(v21[0]));
    seq_putc(a1, 10);
    if ( *((_DWORD *)v1 + 548) )
    {
      v6 = 0;
      v7 = v1 + 276;
      while ( v6 != 9 )
      {
        v8 = *(v7 - 1);
        if ( v8 )
        {
          if ( *v7 )
            seq_printf(
              a1,
              "\tmixer:%d ctl:%d width:%d height:%d\n",
              *(_DWORD *)(v8 + 32) - 1,
              *(_DWORD *)(*v7 + 64) - 1,
              v4,
              v5);
          else
            seq_printf(a1, "\tmixer[%d] has no ctl\n", (unsigned int)v6);
        }
        else
        {
          seq_printf(a1, "\tmixer[%d] has no lm\n", (unsigned int)v6);
        }
        ++v6;
        v7 += 6;
        if ( v6 >= *((unsigned int *)v1 + 548) )
          goto LABEL_14;
      }
LABEL_33:
      __break(0x5512u);
    }
LABEL_14:
    v10 = seq_putc(a1, 10);
    if ( *(_DWORD *)(v3 + 1808) )
    {
      v11 = 0;
      v12 = (unsigned __int16 *)(v3 + 1850);
      while ( v11 != 8 )
      {
        seq_printf(a1, "\tdim_layer:%d] stage:%d flags:%d\n", v11, *(_DWORD *)(v12 - 13), *(_DWORD *)(v12 - 15));
        seq_printf(a1, "\tdst_x:%d dst_y:%d dst_w:%d dst_h:%d\n", *(v12 - 3), *(v12 - 2), *(v12 - 1), *v12);
        seq_printf(
          a1,
          "\tcolor_0:%d color_1:%d color_2:%d color_3:%d\n",
          *(_DWORD *)(v12 - 11),
          *(_DWORD *)(v12 - 9),
          *(_DWORD *)(v12 - 7),
          *(_DWORD *)(v12 - 5));
        v10 = seq_putc(a1, 10);
        ++v11;
        v12 += 16;
        if ( v11 >= *(unsigned int *)(v3 + 1808) )
          goto LABEL_18;
      }
      goto LABEL_33;
    }
LABEL_18:
    v13 = *v1;
    v14 = *(__int64 **)(*v1 + 840);
    if ( v14 != (__int64 *)(*v1 + 840) )
    {
      do
      {
        if ( ((*(_DWORD *)(v1[251] + 12) >> *((_DWORD *)v14 + 437)) & 1) != 0 )
        {
          v15 = v14[220];
          if ( v15 )
          {
            seq_printf(
              a1,
              "\tplane:%u stage:%d rotation:%d\n",
              *((_DWORD *)v14 + 24),
              *(_DWORD *)(v15 + 1760),
              *(_DWORD *)(v15 + 2740));
            v16 = *(_QWORD *)(v14[220] + 16);
            if ( v16 )
            {
              seq_printf(
                a1,
                "\tfb:%d image format:%4.4s wxh:%ux%u ",
                *(_DWORD *)(v16 + 24),
                *(const char **)(v16 + 72),
                *(_DWORD *)(v16 + 128),
                *(_DWORD *)(v16 + 132));
              seq_printf(a1, "cpp[%d]:%u ", 0, *(unsigned __int8 *)(*(_QWORD *)(v16 + 72) + 6LL));
              seq_printf(a1, "cpp[%d]:%u ", 1, *(unsigned __int8 *)(*(_QWORD *)(v16 + 72) + 7LL));
              seq_printf(a1, "cpp[%d]:%u ", 2, *(unsigned __int8 *)(*(_QWORD *)(v16 + 72) + 8LL));
              seq_printf(a1, "cpp[%d]:%u ", 3, *(unsigned __int8 *)(*(_QWORD *)(v16 + 72) + 9LL));
              seq_write(a1, "\n\t", 2);
              seq_printf(a1, "modifier:%8llu ", *(_QWORD *)(v16 + 120));
              seq_putc(a1, 10);
              seq_putc(a1, 9);
              seq_printf(a1, "pitches[%d]:%8u ", 0, *(_DWORD *)(v16 + 88));
              seq_printf(a1, "pitches[%d]:%8u ", 1, *(_DWORD *)(v16 + 92));
              seq_printf(a1, "pitches[%d]:%8u ", 2, *(_DWORD *)(v16 + 96));
              seq_printf(a1, "pitches[%d]:%8u ", 3, *(_DWORD *)(v16 + 100));
              seq_putc(a1, 10);
              seq_putc(a1, 9);
              seq_printf(a1, "offsets[%d]:%8u ", 0, *(_DWORD *)(v16 + 104));
              seq_printf(a1, "offsets[%d]:%8u ", 1, *(_DWORD *)(v16 + 108));
              seq_printf(a1, "offsets[%d]:%8u ", 2, *(_DWORD *)(v16 + 112));
              seq_printf(a1, "offsets[%d]:%8u ", 3, *(_DWORD *)(v16 + 116));
              seq_putc(a1, 10);
            }
            seq_printf(
              a1,
              "\tsrc_x:%4d src_y:%4d src_w:%4d src_h:%4d\n",
              *(unsigned __int16 *)(v15 + 50),
              *(unsigned __int16 *)(v15 + 54),
              *(unsigned __int16 *)(v15 + 62),
              *(unsigned __int16 *)(v15 + 58));
            seq_printf(
              a1,
              "\tdst x:%4d dst_y:%4d dst_w:%4d dst_h:%4d\n",
              *(_DWORD *)(v15 + 32),
              *(_DWORD *)(v15 + 36),
              *(_DWORD *)(v15 + 40),
              *(_DWORD *)(v15 + 44));
            seq_printf(a1, "\tmultirect: mode: %d index: %d\n", *(_DWORD *)(v15 + 1780), *(_DWORD *)(v15 + 1776));
            seq_printf(
              a1,
              "\texcl_rect: x:%4d y:%4d w:%4d h:%4d\n",
              *(unsigned __int16 *)(v15 + 1764),
              *(unsigned __int16 *)(v15 + 1766),
              *(unsigned __int16 *)(v15 + 1768),
              *(unsigned __int16 *)(v15 + 1770));
            v10 = seq_putc(a1, 10);
            v13 = *v1;
          }
        }
        v14 = (__int64 *)*v14;
      }
      while ( v14 != (__int64 *)(v13 + 840) );
    }
    if ( *((_DWORD *)v1 + 1102) )
    {
      v17 = ktime_get(v10);
      v18 = *((_DWORD *)v1 + 1102);
      v19 = (v17 - v1[553]) / 1000000;
      if ( (_DWORD)v19 )
        v20 = (1000 * v18 + ((unsigned int)v19 >> 1)) / (unsigned int)v19;
      else
        v20 = 0;
      seq_printf(a1, "vblank fps:%lld count:%u total:%llums total_framecount:%llu\n", v20, v18, v19, v1[552]);
      *((_DWORD *)v1 + 1102) = 0;
      v1[553] = 0;
    }
    mutex_unlock(v1 + 577);
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
