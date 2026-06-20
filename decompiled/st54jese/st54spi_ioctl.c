__int64 __fastcall st54spi_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v5; // x10
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x9
  __int64 v8; // x10
  unsigned __int64 v9; // x9
  __int64 result; // x0
  __int64 v11; // x19
  __int64 v14; // x20
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned __int64 v17; // x1
  unsigned __int64 v18; // x8
  __int64 v19; // x9
  unsigned __int64 v20; // x8
  __int64 v22; // x0
  int v28; // w23
  int v29; // w21
  unsigned __int64 v30; // x8
  __int64 v31; // x9
  unsigned __int64 v32; // x8
  __int64 v34; // x0
  unsigned __int64 v35; // x8
  __int64 v36; // x9
  unsigned __int64 v37; // x8
  __int64 v39; // x0
  int v41; // w22
  __int64 v42; // x0
  unsigned __int64 v43; // x8
  __int64 v44; // x9
  unsigned __int64 v45; // x8
  __int64 v46; // x0
  unsigned __int64 v48; // x8
  __int64 v49; // x9
  unsigned __int64 v50; // x8
  __int64 v52; // x0
  unsigned __int64 v54; // x8
  __int64 v55; // x9
  unsigned __int64 v56; // x8
  __int64 v58; // x0
  char v60; // w22
  unsigned __int64 v61; // x8
  __int64 v62; // x9
  unsigned __int64 v63; // x8
  __int64 v65; // x0
  __int64 v67; // x0
  int v68; // w0
  __int64 v69; // x0
  int v70; // w22
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  unsigned int v74; // w8
  __int64 v75; // x0
  int v76; // w0
  unsigned __int64 v77; // x8
  __int64 v78; // x9
  unsigned __int64 v79; // x8
  unsigned __int64 v81; // x8
  __int64 v82; // x9
  unsigned __int64 v83; // x8
  unsigned __int64 v85; // x8
  __int64 v86; // x9
  unsigned __int64 v87; // x8
  unsigned __int64 v89; // x8
  __int64 v90; // x9
  unsigned __int64 v91; // x8
  unsigned __int64 v93; // x8
  __int64 v94; // x9
  unsigned __int64 v95; // x8
  unsigned __int64 ioc_message; // x0
  unsigned __int64 v98; // x22
  void *v99; // x0
  unsigned int v100; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v101; // [xsp+8h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v100 = 0;
  if ( (a2 & 0xFF00) != 0x6B00 )
  {
    result = -25;
    goto LABEL_14;
  }
  v3 = HIWORD(a2) & 0x3FFF;
  if ( (a2 & 0x80000000) == 0 )
    goto LABEL_11;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v5 = *(_QWORD *)StatusReg, v6 = a3, (v5 & 0x4000000) != 0) )
    v6 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( 0x8000000000LL - v3 >= v6 )
  {
LABEL_11:
    if ( (a2 & 0x40000000) == 0 )
      goto LABEL_15;
    v7 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v7 + 70) & 0x20) != 0 || (v8 = *(_QWORD *)v7, v9 = a3, (v8 & 0x4000000) != 0) )
      v9 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( 0x8000000000LL - v3 >= v9 )
    {
LABEL_15:
      v11 = *(_QWORD *)(a1 + 32);
      raw_spin_lock_irq(v11 + 4);
      v14 = *(_QWORD *)(v11 + 8);
      if ( v14 && !get_device(*(_QWORD *)(v11 + 8)) )
        v14 = 0;
      raw_spin_unlock_irq(v11 + 4);
      v15 = *(_QWORD *)(v11 + 8);
      if ( !v15 )
        v15 = *(_QWORD *)(v11 + 16);
      dev_info(v15, "st54spi ioctl cmd %d\n", a2);
      if ( !v14 )
      {
        result = -108;
        goto LABEL_14;
      }
      v16 = mutex_lock(v11 + 40);
      if ( a2 <= 27489 )
      {
        v17 = a3;
        if ( a2 > -2147194109 )
        {
          switch ( a2 )
          {
            case -2147194108:
              v85 = _ReadStatusReg(SP_EL0);
              if ( (*(_BYTE *)(v85 + 70) & 0x20) != 0 || (v86 = *(_QWORD *)v85, v87 = a3, (v86 & 0x4000000) != 0) )
                v87 = a3 & ((__int64)(a3 << 8) >> 8);
              if ( v87 > 0x7FFFFFFFFCLL )
                goto LABEL_112;
              _W22 = *(_DWORD *)(v11 + 120);
              v34 = uaccess_ttbr0_enable(v16);
              __asm { STTR            W22, [X21] }
              break;
            case -2147194107:
              v93 = _ReadStatusReg(SP_EL0);
              if ( (*(_BYTE *)(v93 + 70) & 0x20) != 0 || (v94 = *(_QWORD *)v93, v95 = a3, (v94 & 0x4000000) != 0) )
                v95 = a3 & ((__int64)(a3 << 8) >> 8);
              if ( v95 > 0x7FFFFFFFFCLL )
                goto LABEL_112;
              _W22 = *(_DWORD *)(v14 + 944) & 0xFFF;
              v34 = uaccess_ttbr0_enable(v16);
              __asm { STTR            W22, [X21] }
              break;
            case -2147194013:
              v43 = _ReadStatusReg(SP_EL0);
              if ( (*(_BYTE *)(v43 + 70) & 0x20) != 0 || (v44 = *(_QWORD *)v43, v45 = a3, (v44 & 0x4000000) != 0) )
                v45 = a3 & ((__int64)(a3 << 8) >> 8);
              if ( v45 > 0x7FFFFFFFFCLL )
                goto LABEL_112;
              v46 = st54spi_power_get(v11);
              _W21 = v46;
              v34 = uaccess_ttbr0_enable(v46);
              __asm { STTR            W21, [X22] }
              break;
            default:
              goto LABEL_113;
          }
        }
        else
        {
          switch ( a2 )
          {
            case -2147390719:
              v81 = _ReadStatusReg(SP_EL0);
              if ( (*(_BYTE *)(v81 + 70) & 0x20) != 0 || (v82 = *(_QWORD *)v81, v83 = a3, (v82 & 0x4000000) != 0) )
                v83 = a3 & ((__int64)(a3 << 8) >> 8);
              if ( v83 >> 39 )
                goto LABEL_112;
              _W22 = *(_DWORD *)(v14 + 944);
              v34 = uaccess_ttbr0_enable(v16);
              __asm { STTRB           W22, [X21] }
              break;
            case -2147390718:
              v89 = _ReadStatusReg(SP_EL0);
              if ( (*(_BYTE *)(v89 + 70) & 0x20) != 0 || (v90 = *(_QWORD *)v89, v91 = a3, (v90 & 0x4000000) != 0) )
                v91 = a3 & ((__int64)(a3 << 8) >> 8);
              if ( v91 >> 39 )
                goto LABEL_112;
              _W22 = (*(unsigned __int8 *)(v14 + 944) >> 3) & 1;
              v34 = uaccess_ttbr0_enable(v16);
              __asm { STTRB           W22, [X21] }
              break;
            case -2147390717:
              v30 = _ReadStatusReg(SP_EL0);
              if ( (*(_BYTE *)(v30 + 70) & 0x20) != 0 || (v31 = *(_QWORD *)v30, v32 = a3, (v31 & 0x4000000) != 0) )
                v32 = a3 & ((__int64)(a3 << 8) >> 8);
              if ( v32 >> 39 )
                goto LABEL_112;
              _W22 = *(unsigned __int8 *)(v14 + 940);
              v34 = uaccess_ttbr0_enable(v16);
              __asm { STTRB           W22, [X21] }
              break;
            default:
              goto LABEL_113;
          }
        }
        uaccess_ttbr0_disable(v34);
        goto LABEL_118;
      }
      v17 = a3;
      if ( a2 <= 1073834754 )
      {
        if ( a2 == 27490 )
        {
          dev_info(v14, "SE_CHIP_EN pulse requested, %d\n", *(_DWORD *)(v11 + 132));
          if ( *(_DWORD *)(v11 + 132) )
          {
            v67 = ((__int64 (*)(void))gpio_to_desc)();
            v68 = gpiod_direction_output_raw(v67, 1);
            if ( v68 )
            {
              v29 = v68;
              v99 = &unk_8F5C;
            }
            else
            {
              v69 = gpio_to_desc(*(unsigned int *)(v11 + 132));
              gpiod_set_raw_value(v69, 0);
              v70 = st54spi_power_get(v11);
              if ( v70 )
                st54spi_power_off(v11);
              usleep_range_state(1500, 2000, 2);
              v71 = gpio_to_desc(*(unsigned int *)(v11 + 132));
              v72 = gpiod_set_raw_value(v71, 1);
              v73 = ktime_get(v72);
              v74 = *(_DWORD *)(v11 + 132);
              *(_QWORD *)(v11 + 192) = v73;
              v75 = gpio_to_desc(v74);
              v76 = gpiod_direction_input(v75);
              if ( !v76 )
              {
                dev_info(v14, "SE_CHIP_EN pulse done\n");
                if ( v70 )
                  st54spi_power_on(v11);
                goto LABEL_118;
              }
              v29 = v76;
              v99 = &unk_8EB8;
            }
            printk(v99, "st54spi_ioctl");
            goto LABEL_119;
          }
LABEL_118:
          v29 = 0;
          goto LABEL_119;
        }
        if ( a2 != 1073834753 )
        {
          if ( a2 != 1073834754 )
            goto LABEL_113;
          v35 = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(v35 + 70) & 0x20) != 0 || (v36 = *(_QWORD *)v35, v37 = a3, (v36 & 0x4000000) != 0) )
            v37 = a3 & ((__int64)(a3 << 8) >> 8);
          if ( v37 >> 39 )
            goto LABEL_112;
          _X21 = a3 & 0xFF7FFFFFFFFFFFFFLL;
          v39 = uaccess_ttbr0_enable(v16);
          __asm { LDTRB           W21, [X21] }
          uaccess_ttbr0_disable(v39);
          v41 = *(_DWORD *)(v14 + 944);
          v42 = v14;
          *(_DWORD *)(v14 + 944) = v41 & 0xFFFFFFF7 | (8 * ((unsigned __int8)_X21 != 0));
LABEL_91:
          v29 = spi_setup(v42);
          if ( v29 < 0 )
            *(_DWORD *)(v14 + 944) = v41;
          goto LABEL_119;
        }
        v77 = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(v77 + 70) & 0x20) != 0 || (v78 = *(_QWORD *)v77, v79 = a3, (v78 & 0x4000000) != 0) )
          v79 = a3 & ((__int64)(a3 << 8) >> 8);
        if ( v79 >> 39 )
          goto LABEL_112;
        _X21 = a3 & 0xFF7FFFFFFFFFFFFFLL;
        v65 = uaccess_ttbr0_enable(v16);
        __asm { LDTRB           W8, [X21] }
        LODWORD(_X21) = (unsigned __int8)_X8;
      }
      else
      {
        if ( a2 <= 1074031364 )
        {
          if ( a2 != 1073834755 )
          {
            if ( a2 == 1074031364 )
            {
              v18 = _ReadStatusReg(SP_EL0);
              if ( (*(_BYTE *)(v18 + 70) & 0x20) != 0 || (v19 = *(_QWORD *)v18, v20 = a3, (v19 & 0x4000000) != 0) )
                v20 = a3 & ((__int64)(a3 << 8) >> 8);
              if ( v20 <= 0x7FFFFFFFFCLL )
              {
                _X21 = a3 & 0xFF7FFFFFFFFFFFFFLL;
                v22 = uaccess_ttbr0_enable(v16);
                __asm { LDTR            W22, [X21] }
                uaccess_ttbr0_disable(v22);
                v28 = *(_DWORD *)(v14 + 920);
                *(_DWORD *)(v14 + 920) = _X22;
                v29 = spi_setup(v14);
                if ( (v29 & 0x80000000) == 0 )
                  *(_DWORD *)(v11 + 120) = _X22;
                *(_DWORD *)(v14 + 920) = v28;
                goto LABEL_119;
              }
              goto LABEL_112;
            }
            goto LABEL_113;
          }
          v54 = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(v54 + 70) & 0x20) != 0 || (v55 = *(_QWORD *)v54, v56 = a3, (v55 & 0x4000000) != 0) )
            v56 = a3 & ((__int64)(a3 << 8) >> 8);
          if ( !(v56 >> 39) )
          {
            _X21 = a3 & 0xFF7FFFFFFFFFFFFFLL;
            v58 = uaccess_ttbr0_enable(v16);
            __asm { LDTRB           W21, [X21] }
            uaccess_ttbr0_disable(v58);
            v60 = *(_BYTE *)(v14 + 940);
            *(_BYTE *)(v14 + 940) = _X21;
            v29 = spi_setup(v14);
            if ( v29 < 0 )
              *(_BYTE *)(v14 + 940) = v60;
            goto LABEL_119;
          }
LABEL_112:
          v29 = -14;
LABEL_119:
          mutex_unlock(v11 + 40);
          put_device(v14);
          dev_info(v14, "st54spi ioctl retval %d\n", v29);
          result = v29;
          goto LABEL_14;
        }
        if ( a2 != 1074031365 )
        {
          if ( a2 == 1074031459 )
          {
            v48 = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(v48 + 70) & 0x20) != 0 || (v49 = *(_QWORD *)v48, v50 = a3, (v49 & 0x4000000) != 0) )
              v50 = a3 & ((__int64)(a3 << 8) >> 8);
            if ( v50 <= 0x7FFFFFFFFCLL )
            {
              _X21 = a3 & 0xFF7FFFFFFFFFFFFFLL;
              v52 = uaccess_ttbr0_enable(v16);
              __asm { LDTR            W21, [X21] }
              uaccess_ttbr0_disable(v52);
              st54spi_power_set(v11, (_DWORD)_X21 != 0);
              goto LABEL_118;
            }
            goto LABEL_112;
          }
LABEL_113:
          ioc_message = st54spi_get_ioc_message((unsigned int)a2, v17, &v100);
          if ( ioc_message >= 0xFFFFFFFFFFFFF001LL )
          {
            v29 = ioc_message;
            goto LABEL_119;
          }
          if ( ioc_message )
          {
            v98 = ioc_message;
            st54spi_check_tready(v11);
            v29 = st54spi_message(v11, v98, v100);
            kfree(v98);
            goto LABEL_119;
          }
          goto LABEL_118;
        }
        v61 = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(v61 + 70) & 0x20) != 0 || (v62 = *(_QWORD *)v61, v63 = a3, (v62 & 0x4000000) != 0) )
          v63 = a3 & ((__int64)(a3 << 8) >> 8);
        if ( v63 > 0x7FFFFFFFFCLL )
          goto LABEL_112;
        _X21 = a3 & 0xFF7FFFFFFFFFFFFFLL;
        v65 = uaccess_ttbr0_enable(v16);
        __asm { LDTR            W21, [X21] }
      }
      uaccess_ttbr0_disable(v65);
      if ( (_X21 & 0xFFFFF000) != 0 )
      {
        v29 = -22;
        goto LABEL_119;
      }
      v41 = *(_DWORD *)(v14 + 944);
      v42 = v14;
      *(_DWORD *)(v14 + 944) = v41 & 0xF000 | _X21;
      goto LABEL_91;
    }
  }
  result = -14;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
