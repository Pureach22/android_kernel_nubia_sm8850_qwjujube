__int64 __fastcall swr_mstr_interrupt(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  unsigned int v4; // w22
  unsigned int v5; // w0
  _QWORD **v6; // x28
  int v7; // w24
  int v8; // w21
  int v9; // w20
  __int16 v10; // w9
  int v11; // w2
  __int64 v12; // x0
  unsigned __int16 v13; // w1
  int v14; // w26
  int v15; // w26
  int v16; // w26
  int v17; // w0
  int v18; // w8
  unsigned int v19; // w23
  int v20; // w8
  _QWORD *i; // x22
  unsigned int v22; // w26
  int v23; // w22
  unsigned int v25; // w26
  unsigned int v26; // w26
  int v27; // w0
  int v28; // w8
  int v29; // w11
  unsigned int v30; // w9
  int v31; // w10
  int v32; // w11
  int v33; // w12
  _BYTE *v34; // x14
  _QWORD *j; // x8
  _BYTE *v36; // x22
  unsigned __int64 v37; // x26
  __int64 v38; // x23
  __int64 v39; // x3
  char v40; // w8
  int v41; // w3
  char v42; // w8
  int v43; // w3
  char v44; // w8
  _QWORD *v45; // x26
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  int v50; // w8
  __int64 v51; // x0
  int v52; // w8
  int v53; // w8
  char v55; // [xsp+10h] [xbp-30h]
  unsigned int v56; // [xsp+14h] [xbp-2Ch]
  int v57; // [xsp+18h] [xbp-28h]
  int v58; // [xsp+1Ch] [xbp-24h] BYREF
  __int64 v59; // [xsp+20h] [xbp-20h] BYREF
  _WORD v60[7]; // [xsp+28h] [xbp-18h] BYREF
  __int64 v61; // [xsp+38h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  if ( (swrm_lock_sleep(a2) & 1) != 0 )
  {
    v3 = a2 + 8832;
    mutex_lock(a2 + 8832);
    v4 = 0;
    if ( (unsigned int)swrm_request_hw_vote(a2, 0, 1) )
    {
LABEL_156:
      mutex_unlock(v3);
      mutex_lock(a2 + 8880);
      v53 = *(_DWORD *)(a2 + 15832) - 1;
      *(_DWORD *)(a2 + 15832) = v53;
      if ( !v53 )
      {
        if ( *(_DWORD *)(a2 + 15800) == 1 )
          *(_DWORD *)(a2 + 15800) = 0;
        cpu_latency_qos_update_request(a2 + 15752, 0xFFFFFFFFLL);
        pm_relax(*(_QWORD *)(a2 + 8512));
      }
      mutex_unlock(a2 + 8880);
      _wake_up(a2 + 15808, 3, 0, 0);
      goto LABEL_161;
    }
    if ( (unsigned int)swrm_request_hw_vote(a2, 1, 1) )
    {
      v4 = 0;
LABEL_150:
      mutex_lock(a2 + 8736);
      v51 = *(_QWORD *)(a2 + 15848);
      if ( v51 )
      {
        v52 = *(_DWORD *)(a2 + 15872) - 1;
        *(_DWORD *)(a2 + 15872) = v52;
        if ( v52 < 0 )
        {
          *(_DWORD *)(a2 + 15872) = 0;
        }
        else if ( !v52 )
        {
          digital_cdc_rsc_mgr_hw_vote_disable(v51, *(_QWORD *)(a2 + 8512));
        }
      }
      mutex_unlock(a2 + 8736);
      goto LABEL_156;
    }
    if ( (unsigned int)swrm_clk_request(a2, 1) )
    {
      if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_169, "swr_mstr_interrupt") )
        dev_err(a2, "%s: swrm clk failed\n", "swr_mstr_interrupt");
      v4 = 0;
      goto LABEL_144;
    }
    mutex_unlock(a2 + 8832);
    v5 = swr_master_read(a2, (*(_WORD *)(a2 + 9056) << 12) + 0x4000);
    v6 = (_QWORD **)(a2 + 984);
    v7 = 5;
    v8 = *(_DWORD *)(a2 + 15836) & v5;
    v55 = 0;
    v57 = 0;
LABEL_10:
    v9 = 0;
    v56 = v5;
    while ( 1 )
    {
      v14 = (1 << v9) & v8;
      if ( v14 > 255 )
      {
        if ( v14 <= 4095 )
        {
          if ( v14 <= 1023 )
          {
            if ( v14 == 256 )
            {
              if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_183, "swr_mstr_interrupt") )
                dev_err(*(_QWORD *)(a2 + 8512), "%s: SWR Port collision detected\n", "swr_mstr_interrupt");
              v10 = *(_WORD *)(a2 + 9056);
              v11 = *(_DWORD *)(a2 + 15836) & 0xFFFFFEFF;
              goto LABEL_14;
            }
            if ( v14 == 512 )
            {
              v10 = *(_WORD *)(a2 + 9056);
              v11 = *(_DWORD *)(a2 + 15836) & 0xFFFFFDFF;
LABEL_14:
              v12 = a2;
              *(_DWORD *)(a2 + 15836) = v11;
              v13 = (v10 << 12) + 16388;
LABEL_15:
              swr_master_write(v12, v13, v11);
              goto LABEL_16;
            }
          }
          else
          {
            if ( v14 == 1024 )
            {
              complete(a2 + 8608);
              goto LABEL_16;
            }
            if ( v14 == 2048 )
            {
              swr_master_write(a2, 0x500u, 0);
              ++v7;
              do
                --v7;
              while ( (unsigned int)swr_master_read(a2, 0x504u) && v7 );
              v12 = a2;
              v13 = 1280;
LABEL_51:
              v11 = 1;
              goto LABEL_15;
            }
          }
        }
        else if ( v14 < 0x4000 )
        {
          if ( v14 == 4096 )
            goto LABEL_16;
          if ( v14 == 0x2000 )
          {
            if ( *(int *)(a2 + 9128) >= 17104898 )
            {
              v23 = -100;
              while ( (swr_master_read(a2, ((unsigned __int16)*(_DWORD *)(a2 + 9056) << 12) + 16484) & 1) == 0 )
              {
                usleep_range_state(500, 510, 2);
                if ( __CFADD__(v23++, 1) )
                {
                  if ( (unsigned int)__ratelimit(&swrm_check_link_status__rs, "swrm_check_link_status") )
                    dev_err(*(_QWORD *)(a2 + 8512), "%s: link status not %s\n", "swrm_check_link_status", "connected");
                  goto LABEL_16;
                }
              }
            }
            goto LABEL_16;
          }
        }
        else
        {
          switch ( v14 )
          {
            case 0x4000:
              goto LABEL_16;
            case 0x10000:
              if ( *(_DWORD *)(a2 + 15336) != 2 )
              {
                if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_185, "swr_mstr_interrupt") )
                  dev_err(*(_QWORD *)(a2 + 8512), "%s: SWR wokeup during clock stop\n", "swr_mstr_interrupt");
                *(_BYTE *)(a2 + 15908) = 1;
                swrm_enable_slave_irq(a2);
                *(_BYTE *)(a2 + 15908) = 0;
              }
              goto LABEL_16;
            case 0x80000:
              v16 = swr_master_read(a2, ((unsigned __int16)*(_DWORD *)(a2 + 9056) << 12) + 16464);
              if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_187, "swr_mstr_interrupt") )
                dev_err(*(_QWORD *)(a2 + 8512), "%s: SWR CMD Ignored, fifo status 0x%x\n", "swr_mstr_interrupt", v16);
              usleep_range_state(3500, 3505, 2);
              goto LABEL_16;
          }
        }
      }
      else if ( v14 <= 7 )
      {
        if ( v14 > 1 )
        {
          if ( v14 == 2 )
            goto LABEL_16;
          if ( v14 == 4 )
          {
            mutex_lock(&enumeration_lock);
            swrm_enable_slave_irq(a2);
            v59 = 0;
            memset(v60, 0, sizeof(v60));
            if ( (unsigned int)swr_master_read(a2, 0x1090u) == *(_DWORD *)(a2 + 9144) )
            {
              if ( *(_DWORD *)(a2 + 9052) == 3 )
              {
                for ( i = *v6; i != v6; i = (_QWORD *)*i )
                  swr_reset_device(i - 6);
              }
              goto LABEL_135;
            }
            v59 = 0;
            memset(v60, 0, sizeof(v60));
            v27 = swr_master_read(a2, 0x1090u);
            v28 = *(_DWORD *)(a2 + 9144);
            if ( v27 != v28 )
            {
              v29 = *(_DWORD *)(a2 + 9140);
              if ( v29 != -1 )
              {
                v30 = 0;
                v31 = 0;
                v32 = v29 + 1;
                v33 = v27;
                do
                {
                  if ( (v33 & 3) != (v28 & 3) )
                  {
                    if ( v30 > 0xA )
                    {
LABEL_165:
                      __break(1u);
LABEL_166:
                      __break(0x5512u);
                    }
                    v34 = &v60[v30++ - 4];
                    *v34 = v31;
                    v34[1] = v33 & 3;
                  }
                  ++v31;
                  v33 >>= 2;
                  v28 >>= 2;
                }
                while ( v32 != v31 );
                *(_DWORD *)(a2 + 9144) = v27;
                if ( !v30 )
                  goto LABEL_135;
                v36 = (char *)&v59 + 1;
                v37 = 0;
                v38 = v30;
                while ( 2 )
                {
                  if ( v37 == 11 )
                    goto LABEL_166;
                  if ( v37 > 0xA )
                    goto LABEL_165;
                  if ( *v36 != 1 )
                  {
                    if ( !*v36 && !*(v36 - 1) )
LABEL_109:
                      *(_BYTE *)(a2 + 15900) = 1;
                    ++v37;
                    v36 += 2;
                    if ( v38 == v37 )
                      goto LABEL_135;
                    continue;
                  }
                  break;
                }
                swrm_initialize_clk_base_scale(a2, (unsigned __int8)*(v36 - 1));
                goto LABEL_109;
              }
              *(_DWORD *)(a2 + 9144) = v27;
            }
LABEL_135:
            mutex_unlock(&enumeration_lock);
            goto LABEL_16;
          }
        }
        else
        {
          if ( !v14 )
            goto LABEL_16;
          if ( v14 == 1 )
          {
            v17 = swr_master_read(a2, 0x1090u);
            v18 = *(_DWORD *)(a2 + 9140);
            if ( v18 == -1 )
            {
LABEL_41:
              if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_171, "swr_mstr_interrupt") )
                dev_err(*(_QWORD *)(a2 + 8512), "%s: no slave alert found.spurious interrupt\n", "swr_mstr_interrupt");
              v57 = -22;
            }
            else
            {
              v19 = 0;
              v20 = v18 + 1;
              while ( (v17 & 3) != 2 )
              {
                ++v19;
                v17 >>= 2;
                if ( v20 == v19 )
                  goto LABEL_41;
              }
              for ( j = *v6; j != v6; j = (_QWORD *)*j )
              {
                if ( *((unsigned __int8 *)j + 16) == (unsigned __int8)v19 && *((_BYTE *)j + 946) == 1 )
                {
                  swr_device_handle_interrupt(j - 6, v19);
LABEL_105:
                  v57 = 0;
                  v55 = 1;
                  goto LABEL_16;
                }
              }
              if ( (v55 & 1) != 0 )
                goto LABEL_105;
              v39 = *(unsigned __int8 *)(a2 + 9050);
              v40 = (v39 + 1) & 0xF;
              if ( (_DWORD)v39 == 14 )
                v40 = 0;
              *(_BYTE *)(a2 + 9050) = v40;
              swrm_cmd_fifo_rd_cmd(a2, &v58, v19, v39, 64, 1);
              v41 = *(unsigned __int8 *)(a2 + 9050);
              v42 = (v41 + 1) & 0xF;
              if ( v41 == 14 )
                v42 = 0;
              *(_BYTE *)(a2 + 9050) = v42;
              swrm_cmd_fifo_wr_cmd(a2, 4, v19, v41, 0x40u);
              v43 = *(unsigned __int8 *)(a2 + 9050);
              v44 = (v43 + 1) & 0xF;
              if ( v43 == 14 )
                v44 = 0;
              *(_BYTE *)(a2 + 9050) = v44;
              swrm_cmd_fifo_wr_cmd(a2, 0, v19, v43, 0x40u);
              v45 = *(_QWORD **)(a2 + 984);
              if ( v45 == v6 )
              {
                v55 = 0;
                v57 = 0;
              }
              else
              {
                do
                {
                  if ( *((unsigned __int8 *)v45 + 16) == (unsigned __int8)v19 && v45[119] )
                  {
                    do
                    {
                      v46 = v45[119];
                      *((_BYTE *)v45 + 960) = 0;
                      LODWORD(v59) = 0;
                      if ( _irq_resolve_mapping(v46, 0, &v59) )
                        v47 = (unsigned int)v59;
                      else
                        v47 = 0;
                      handle_nested_irq(v47);
                    }
                    while ( *((_BYTE *)v45 + 960) == 1 && (*(_BYTE *)(a2 + 15748) & 1) != 0 );
                  }
                  v45 = (_QWORD *)*v45;
                }
                while ( v45 != v6 );
                v55 = 0;
                v57 = 0;
              }
            }
            goto LABEL_16;
          }
        }
      }
      else if ( v14 <= 31 )
      {
        if ( v14 == 8 )
        {
          if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_173, "swr_mstr_interrupt") )
            dev_err(*(_QWORD *)(a2 + 8512), "%s: SWR bus clsh detected\n", "swr_mstr_interrupt");
          v10 = *(_WORD *)(a2 + 9056);
          v11 = *(_DWORD *)(a2 + 15836) & 0xFFFFFFF7;
          goto LABEL_14;
        }
        if ( v14 == 16 )
        {
          v22 = swr_master_read(a2, ((unsigned __int16)*(_DWORD *)(a2 + 9056) << 12) + 16464);
          if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_175, "swr_mstr_interrupt") )
            dev_err(*(_QWORD *)(a2 + 8512), "%s: SWR read FIFO overflow fifo status %x\n", "swr_mstr_interrupt", v22);
          goto LABEL_16;
        }
      }
      else
      {
        switch ( v14 )
        {
          case 32:
            v26 = swr_master_read(a2, ((unsigned __int16)*(_DWORD *)(a2 + 9056) << 12) + 16464);
            if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_177, "swr_mstr_interrupt") )
              dev_err(*(_QWORD *)(a2 + 8512), "%s: SWR read FIFO underflow fifo status %x\n", "swr_mstr_interrupt", v26);
            goto LABEL_16;
          case 64:
            v25 = swr_master_read(a2, ((unsigned __int16)*(_DWORD *)(a2 + 9056) << 12) + 16464);
            if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_179, "swr_mstr_interrupt") )
              dev_err(*(_QWORD *)(a2 + 8512), "%s: SWR write FIFO overflow fifo status %x\n", "swr_mstr_interrupt", v25);
            goto LABEL_16;
          case 128:
            v15 = swr_master_read(a2, ((unsigned __int16)*(_DWORD *)(a2 + 9056) << 12) + 16464);
            if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_181, "swr_mstr_interrupt") )
              dev_err(
                *(_QWORD *)(a2 + 8512),
                "%s: SWR CMD error, fifo status 0x%x, flushing fifo\n",
                "swr_mstr_interrupt",
                v15);
            v12 = a2;
            v13 = 776;
            goto LABEL_51;
        }
      }
      if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs_189, "swr_mstr_interrupt") )
        dev_err(*(_QWORD *)(a2 + 8512), "%s: SWR unknown interrupt value: %d\n", "swr_mstr_interrupt", v14);
      v57 = 0;
LABEL_16:
      if ( ++v9 == 23 )
      {
        swr_master_write(a2, (*(_WORD *)(a2 + 9056) << 12) + 16392, v56);
        swr_master_write(a2, (*(_WORD *)(a2 + 9056) << 12) + 16392, 0);
        if ( *(_BYTE *)(a2 + 15900) == 1 )
        {
          mutex_lock(&enumeration_lock);
          swrm_enable_slave_irq(a2);
          *(_BYTE *)(a2 + 15900) = 0;
          mutex_unlock(&enumeration_lock);
        }
        v5 = swr_master_read(a2, (*(_WORD *)(a2 + 9056) << 12) + 0x4000);
        v8 = *(_DWORD *)(a2 + 15836) & v5;
        if ( !v8 || (v48 = *(_QWORD *)(a2 + 8512), *(_DWORD *)(v48 + 500) == 2) && (*(_WORD *)(v48 + 488) & 7) == 0 )
        {
          v3 = a2 + 8832;
          mutex_lock(a2 + 8832);
          swrm_clk_request(a2, 0);
          v4 = v57;
LABEL_144:
          mutex_lock(a2 + 8736);
          v49 = *(_QWORD *)(a2 + 15856);
          if ( v49 )
          {
            v50 = *(_DWORD *)(a2 + 15876) - 1;
            *(_DWORD *)(a2 + 15876) = v50;
            if ( v50 < 0 )
            {
              *(_DWORD *)(a2 + 15876) = 0;
            }
            else if ( !v50 )
            {
              digital_cdc_rsc_mgr_hw_vote_disable(v49, *(_QWORD *)(a2 + 8512));
            }
          }
          mutex_unlock(a2 + 8736);
          goto LABEL_150;
        }
        goto LABEL_10;
      }
    }
  }
  if ( (unsigned int)__ratelimit(&swr_mstr_interrupt__rs, "swr_mstr_interrupt") )
    dev_err(*(_QWORD *)(a2 + 8512), "%s Failed to hold suspend\n", "swr_mstr_interrupt");
  v4 = 0;
LABEL_161:
  _ReadStatusReg(SP_EL0);
  return v4;
}
