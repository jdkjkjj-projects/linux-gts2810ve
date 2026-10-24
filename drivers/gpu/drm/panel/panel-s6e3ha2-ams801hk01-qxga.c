// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct s6e3ha2_ams801hk01_qxga {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
};

static inline
struct s6e3ha2_ams801hk01_qxga *to_s6e3ha2_ams801hk01_qxga(struct drm_panel *panel)
{
	return container_of_const(panel, struct s6e3ha2_ams801hk01_qxga, panel);
}

static void s6e3ha2_ams801hk01_qxga_reset(struct s6e3ha2_ams801hk01_qxga *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
}

static int s6e3ha2_ams801hk01_qxga_on(struct s6e3ha2_ams801hk01_qxga *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_usleep_range(&dsi_ctx, 5000, 6000);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf2, 0x63);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_msleep(&dsi_ctx, 50);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8, 0x30, 0xb9);
	mipi_dsi_msleep(&dsi_ctx, 40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8, 0x30, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9,
					 0x10, 0x07, 0xff, 0x00, 0x09);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x35, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd,
					 0x11, 0x01, 0x02, 0x16, 0x02, 0x16);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0,
					 0x00, 0x0f, 0xd8, 0xd8);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfc, 0x5a, 0x5a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x20);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfe, 0x08);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfc, 0xa5, 0xa5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xed, 0x44);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x2a,
					 0x00, 0x00, 0x05, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x2b,
					 0x00, 0x00, 0x07, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xca,
					 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
					 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
					 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
					 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
					 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
					 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2, 0x0a, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x9c, 0x0d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf4, 0xab, 0x21);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x55, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf7, 0x03);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf7, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);

	return dsi_ctx.accum_err;
}

static int s6e3ha2_ams801hk01_qxga_off(struct s6e3ha2_ams801hk01_qxga *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int s6e3ha2_ams801hk01_qxga_prepare(struct drm_panel *panel)
{
	struct s6e3ha2_ams801hk01_qxga *ctx = to_s6e3ha2_ams801hk01_qxga(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	s6e3ha2_ams801hk01_qxga_reset(ctx);

	ret = s6e3ha2_ams801hk01_qxga_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	return 0;
}

static int s6e3ha2_ams801hk01_qxga_unprepare(struct drm_panel *panel)
{
	struct s6e3ha2_ams801hk01_qxga *ctx = to_s6e3ha2_ams801hk01_qxga(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = s6e3ha2_ams801hk01_qxga_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	return 0;
}

static const struct drm_display_mode s6e3ha2_ams801hk01_qxga_mode = {
	.clock = (768 + 212 + 16 + 108) * (2048 + 11 + 2 + 5) * 60 / 1000,
	.hdisplay = 768,
	.hsync_start = 768 + 212,
	.hsync_end = 768 + 212 + 16,
	.htotal = 768 + 212 + 16 + 108,
	.vdisplay = 2048,
	.vsync_start = 2048 + 11,
	.vsync_end = 2048 + 11 + 2,
	.vtotal = 2048 + 11 + 2 + 5,
	.width_mm = 122,
	.height_mm = 163,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int s6e3ha2_ams801hk01_qxga_get_modes(struct drm_panel *panel,
					     struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &s6e3ha2_ams801hk01_qxga_mode);
}

static const struct drm_panel_funcs s6e3ha2_ams801hk01_qxga_panel_funcs = {
	.prepare = s6e3ha2_ams801hk01_qxga_prepare,
	.unprepare = s6e3ha2_ams801hk01_qxga_unprepare,
	.get_modes = s6e3ha2_ams801hk01_qxga_get_modes,
};

static int s6e3ha2_ams801hk01_qxga_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int s6e3ha2_ams801hk01_qxga_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness;
}

static const struct backlight_ops s6e3ha2_ams801hk01_qxga_bl_ops = {
	.update_status = s6e3ha2_ams801hk01_qxga_bl_update_status,
	.get_brightness = s6e3ha2_ams801hk01_qxga_bl_get_brightness,
};

static struct backlight_device *
s6e3ha2_ams801hk01_qxga_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 354,
		.max_brightness = 354,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &s6e3ha2_ams801hk01_qxga_bl_ops, &props);
}

static int s6e3ha2_ams801hk01_qxga_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct s6e3ha2_ams801hk01_qxga *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct s6e3ha2_ams801hk01_qxga, panel,
				   &s6e3ha2_ams801hk01_qxga_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO_SYNC_PULSE |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = s6e3ha2_ams801hk01_qxga_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void s6e3ha2_ams801hk01_qxga_remove(struct mipi_dsi_device *dsi)
{
	struct s6e3ha2_ams801hk01_qxga *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id s6e3ha2_ams801hk01_qxga_of_match[] = {
	{ .compatible = "samsung,s6e3ha2-ams801hk01-qxga" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, s6e3ha2_ams801hk01_qxga_of_match);

static struct mipi_dsi_driver s6e3ha2_ams801hk01_qxga_driver = {
	.probe = s6e3ha2_ams801hk01_qxga_probe,
	.remove = s6e3ha2_ams801hk01_qxga_remove,
	.driver = {
		.name = "panel-s6e3ha2-ams801hk01-qxga",
		.of_match_table = s6e3ha2_ams801hk01_qxga_of_match,
	},
};
module_mipi_dsi_driver(s6e3ha2_ams801hk01_qxga_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for ss_dsi_panel_S6E3HA2_AMS801HK01_QXGA");
MODULE_LICENSE("GPL");
