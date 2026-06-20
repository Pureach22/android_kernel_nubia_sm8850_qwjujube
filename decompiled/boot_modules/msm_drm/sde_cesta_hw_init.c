_QWORD *__fastcall sde_cesta_hw_init(_QWORD *result)
{
  result[106] = &sde_cesta_hw_init;
  result[107] = &sde_cesta_hw_ctrl_setup;
  result[108] = sde_cesta_hw_poll_handshake;
  result[109] = sde_cesta_hw_get_status;
  result[110] = sde_cesta_hw_get_pwr_event;
  result[111] = &sde_cesta_hw_override_ctrl_setup;
  result[112] = sde_cesta_hw_reset;
  result[113] = sde_cesta_hw_force_db_update;
  result[114] = sde_get_rscc_pwr_ctrl_status;
  return result;
}
