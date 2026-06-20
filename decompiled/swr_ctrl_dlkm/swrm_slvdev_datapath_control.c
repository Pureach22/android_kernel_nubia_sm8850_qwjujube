__int64 __fastcall swrm_slvdev_datapath_control(__int64 a1, char a2)
{
  __int64 v2; // x19
  char v6; // w0
  __int64 v7; // x8
  unsigned int v8; // w22
  _BOOL4 v9; // w23
  int v10; // w9
  __int64 v11; // x24
  _BOOL4 v12; // w25
  int v13; // w3
  char v14; // w9
  int v16; // w9
  int v17; // w8
  int v18; // w24
  int v19; // w10
  int v20; // w14
  int v21; // w26
  int v22; // w27
  int v23; // w10
  int v24; // w11
  char v25; // w9
  int v26; // w10
  int v27; // w9
  int v28; // w28
  int v29; // w8
  __int64 v30; // x10
  int v31; // w0
  __int64 v32; // x0
  __int64 v33; // x20
  __int64 v34; // x9
  _BYTE *v35; // x8
  __int64 v36; // x10
  unsigned __int64 v42; // x10
  unsigned __int64 v45; // x10
  unsigned __int64 v48; // x10

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 152);
    if ( v2 )
    {
      mutex_lock(v2 + 8784);
      if ( *(_DWORD *)(v2 + 15336) == 4 && (a2 & 1) == 0 )
      {
        if ( (*(_QWORD *)(v2 + 15328) & 2) != 0 )
        {
          _X8 = (unsigned __int64 *)(v2 + 15328);
          __asm { PRFM            #0x11, [X8] }
          do
            v42 = __ldxr(_X8);
          while ( __stxr(v42 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
          v32 = swrm_cleanup_disabled_port_reqs(a1);
LABEL_72:
          if ( !*(_BYTE *)(a1 + 8409) )
          {
            v33 = *(_QWORD *)(v2 + 8512);
            *(_QWORD *)(v33 + 520) = ktime_get_mono_fast_ns(v32);
            _pm_runtime_suspend(*(_QWORD *)(v2 + 8512), 13);
          }
        }
LABEL_74:
        mutex_unlock(v2 + 8784);
        return 0;
      }
      v6 = swr_master_read(v2, 0x104Cu);
      v7 = *(_QWORD *)(v2 + 15328);
      v8 = v6 & 1;
      v9 = !(v6 & 1);
      if ( (a2 & 1) != 0 )
      {
        if ( (v7 & 1) == 0 )
          goto LABEL_74;
        _X8 = (unsigned __int64 *)(v2 + 15328);
        __asm { PRFM            #0x11, [X8] }
        do
          v45 = __ldxr(_X8);
        while ( __stxr(v45 & 0xFFFFFFFFFFFFFFFELL, _X8) );
        v10 = *(_DWORD *)(v2 + 9052);
        if ( v10 != 3 && v10 != 5 )
        {
          if ( v10 == 2 && (*(_BYTE *)(v2 + 9328) & 1) != 0 )
          {
            v30 = 1;
          }
          else if ( v10 == 2 )
          {
            v30 = 2LL * (*(_DWORD *)(v2 + 9136) == 11289600);
          }
          else
          {
            v30 = v10 == 1 && *(_BYTE *)(v2 + 9168) == 1 && *(_DWORD *)(v2 + 9184) == 4800000;
          }
          v34 = 0;
          v35 = (_BYTE *)(v2 + 9183);
          v36 = *(_QWORD *)(*(_QWORD *)(v2 + 15840) + 8 * v30);
          do
          {
            if ( *(v35 - 15) == 1 )
            {
              *(_WORD *)(v35 - 9) = *(_WORD *)(v36 + v34);
              *(v35 - 12) = *(_BYTE *)(v36 + v34 + 2);
              *(v35 - 11) = *(_BYTE *)(v36 + v34 + 3);
              *(v35 - 7) = *(_BYTE *)(v36 + v34 + 4);
              *(v35 - 6) = *(_BYTE *)(v36 + v34 + 5);
              *(v35 - 4) = *(_BYTE *)(v36 + v34 + 7);
              *(v35 - 5) = *(_BYTE *)(v36 + v34 + 8);
              *(v35 - 3) = *(_BYTE *)(v36 + v34 + 6);
              *(v35 - 2) = *(_BYTE *)(v36 + v34 + 9);
              *(v35 - 1) = *(_BYTE *)(v36 + v34 + 10);
              *v35 = *(_BYTE *)(v36 + v34 + 11);
            }
            v34 += 12;
            v35 += 40;
          }
          while ( v34 != 156 );
        }
        swr_master_write(v2, (*(_WORD *)(v2 + 9056) << 12) + 16388, 0x1DFDFDu);
        v11 = *(_QWORD *)(a1 + 152);
        if ( v11 )
        {
          v12 = (swr_master_read(*(_QWORD *)(a1 + 152), 0x104Cu) & 1) == 0;
          if ( !*(_DWORD *)(v11 + 15884) )
          {
            v13 = *(unsigned __int8 *)(v11 + 9050);
            v14 = (v13 + 1) & 0xF;
            if ( v13 == 14 )
              v14 = 0;
            *(_BYTE *)(v11 + 9050) = v14;
            swrm_cmd_fifo_wr_cmd(v11, 1, 0xFu, v13, (16 * v12) | 0xE0);
          }
          swrm_copy_data_port_config(a1, v12);
        }
        else if ( (unsigned int)__ratelimit(&swrm_apply_port_config__rs, "swrm_apply_port_config") )
        {
          printk(&unk_1079B, "swrm_apply_port_config");
        }
        _ZF = *(_DWORD *)(v2 + 9136) == 600000;
      }
      else
      {
        if ( (v7 & 2) == 0 )
          goto LABEL_74;
        _X8 = (unsigned __int64 *)(v2 + 15328);
        __asm { PRFM            #0x11, [X8] }
        do
          v48 = __ldxr(_X8);
        while ( __stxr(v48 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        swrm_disable_ports(a1, !(v6 & 1));
        _ZF = *(_BYTE *)(a1 + 8409) == 0;
      }
      v16 = _ZF;
      v17 = *(_DWORD *)(v2 + 9132);
      if ( v16 )
        v18 = 0;
      else
        v18 = 7;
      if ( v17 == 12288000 )
        v19 = 3;
      else
        v19 = 1;
      if ( v17 == 12288000 )
        v20 = 64;
      else
        v20 = 50;
      v21 = 0;
      if ( v17 == 11289600 )
        v22 = 3;
      else
        v22 = v19;
      if ( v17 == 11289600 )
        v23 = 64;
      else
        v23 = v20;
      if ( v17 == 11289600 )
        v24 = 3675;
      else
        v24 = 4000;
      if ( v16 )
        v25 = 1;
      else
        v25 = 4;
      v26 = v23 << v25;
      v27 = *(_DWORD *)(v2 + 9136);
      v28 = 2 * v27 / (v26 * v24);
      if ( v17 && v27 )
      {
        v29 = v17 / v27;
        if ( v29 <= 7 )
        {
          if ( v29 == 2 )
          {
            v21 = 256;
            goto LABEL_69;
          }
          if ( v29 == 4 )
          {
            v21 = 512;
            goto LABEL_69;
          }
        }
        else
        {
          switch ( v29 )
          {
            case 8:
              v21 = 768;
              goto LABEL_69;
            case 32:
              v21 = 1280;
              goto LABEL_69;
            case 16:
              v21 = 1024;
              goto LABEL_69;
          }
        }
        v21 = 0;
      }
LABEL_69:
      v31 = swr_master_read(v2, (v9 << 6) | 0x101Cu);
      swr_master_write(
        v2,
        (v9 << 6) | 0x101C,
        v31 & 0xFF00F800 | v18 | (((v21 | (8 * v22)) & 0xFF00FFFF | ((unsigned __int8)v28 << 16)) - 0x10000));
      swrm_update_clk_base_and_scale(a1, v9);
      swrm_cmd_fifo_wr_cmd(v2, v18 & 0xFFFFFFE7 | (8 * (v22 & 3)), 0xFu, 0xFu, (16 * v9) | 0x60);
      swrm_update_clk_base_and_scale(a1, v8);
      if ( (a2 & 1) != 0 )
      {
        v32 = swrm_copy_data_port_config(a1, v8);
      }
      else
      {
        swrm_disable_ports(a1, v8);
        v32 = swrm_cleanup_disabled_port_reqs(a1);
      }
      goto LABEL_72;
    }
  }
  if ( (unsigned int)__ratelimit(&swrm_slvdev_datapath_control__rs, "swrm_slvdev_datapath_control") )
    printk(&unk_10D41, "swrm_slvdev_datapath_control");
  return 4294967282LL;
}
